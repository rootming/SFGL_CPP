#include "fbdev.h"
#include "debug.h"

const char *fbdevList[] = {
                     // "/dev/fb",
                      "/dev/fb0",
                      "/dev/fb1",
                      "/dev/fb2",
                      "/dev/graphics/fb0"	//Android 帧缓冲设备?或许也需要fbcon驱动才能使用
                    };

Fbdev* Fbdev::videoDevice = NULL;
int8_t Fbdev::redOffset = 0;
int8_t Fbdev::greenOffset = 0;
int8_t Fbdev::blueOffset = 0;
int8_t Fbdev::alphaOffset = 0;

Fbdev::Fbdev(const int w, const int h)
{
    width = w;
    height = h;
    depth = 32;
    if(videoDevice == NULL){
        if(initFbdev() == EXIT_SUCCESS){
            SFGL_DEBUG_INFO("Init fbdev successful.\n");
        }
        else{
            SFGL_DEBUG_ERROR("Init fbdev fail.\n");
            exit(0);
        }
    }
    buffer = NULL;
    resize(w, h);
    //buffer = new int32_t[width * height * sizeof(int32_t)];
}

Fbdev::~Fbdev()
{
    delete []buffer;
    if(videoDevice == this){
        if(this->data.fbdf != -1){
            munmap(data.fb_mmap, data.fb_var.xres * data.fb_var.yres * sizeof(int32_t));
            close(data.fbdf);
        }
    }
    delete videoDevice;
}

int Fbdev::initFbdev(void)
{
    unsigned int fid = 0;
    data.device = new char[20];
    bool openOK = false;
    while(fid < sizeof(fbdevList) / sizeof(char **)){
        if((data.fbdf = open(fbdevList[fid], O_RDWR)) < 0){
            SFGL_DEBUG_ERROR("Open Framebuffer Device:%s error!\n", fbdevList[fid]);
            //return EXIT_FAILURE;
        }
        else{
            strcpy(data.device, fbdevList[fid]);
            openOK = true;
            //data.device = string(fbdevList[fid]);
            break;
        }
        fid++;

    }
    if(!openOK)
        return EXIT_FAILURE;

    SFGL_DEBUG_INFO("Open Framebuffer Device:%s successful!\n", data.device);
    if(ioctl(data.fbdf, FBIOGET_FSCREENINFO, &data.fb_fix) == -1){
        SFGL_DEBUG_ERROR("Get Fb_fix_info error!\n");
        return EXIT_FAILURE;
    }

    SFGL_DEBUG_INFO("Get Fb_fix_info successful!\n");
    if(ioctl(data.fbdf, FBIOGET_VSCREENINFO, &data.fb_var) == -1){
        SFGL_DEBUG_ERROR("Get Fb_var_info error!\n");
        return EXIT_FAILURE;
    }

    SFGL_DEBUG_INFO("Get Fb_var_info successful!\n");
//    data.fb_mmap = mmap(NULL, bytes(), PROT_READ | PROT_WRITE,
//                          MAP_SHARED, data.fbdf, 0);
        data.fb_mmap = mmap(NULL, data.fb_var.xres * data.fb_var.yres * sizeof(int32_t), PROT_READ | PROT_WRITE,
                              MAP_SHARED, data.fbdf, 0);
    if(data.fb_mmap == NULL){
        SFGL_DEBUG_ERROR("Memory Mmap error!\n");
        return EXIT_FAILURE;
    }

    SFGL_DEBUG_INFO("Memory Mmap successful!\n");
    //printFixedInfo();
    //printVariableInfo();
    data.width = data.fb_var.xres;
    data.height = data.fb_var.yres;
    data.depth = data.fb_var.bits_per_pixel;
    data.fb_size = data.fb_fix.smem_len;
    data.line_length = data.fb_fix.line_length;
    redOffset = data.fb_var.red.offset;
    blueOffset = data.fb_var.blue.offset;
    greenOffset = data.fb_var.green.offset;
    alphaOffset = data.fb_var.transp.offset;
    videoDevice = this;
    return EXIT_SUCCESS;
}

void Fbdev::printFixedInfo(void)
{
    SFGL_DEBUG_INFO("Fixed screen info:\n"
                    "\tid: %s\n"
                    "\tsmem_start: 0x%lx\n"
                    "\tsmem_len: %d\n"
                    "\ttype: %d\n"
                    "\ttype_aux: %d\n"
                    "\tvisual: %d\n"
                    "\txpanstep: %d\n"
                    "\typanstep: %d\n"
                    "\tywrapstep: %d\n"
                    "\tline_length: %d\n"
                    "\tmmio_start: 0x%lx\n"
                    "\tmmio_len: %d\n"
                    "\taccel: %d\n"
                    "\n", data.fb_fix.id, data.fb_fix.smem_start,
                    data.fb_fix.smem_len, data.fb_fix.type, data.fb_fix.type_aux,
                    data.fb_fix.visual, data.fb_fix.xpanstep,
                    data.fb_fix.ypanstep, data.fb_fix.ywrapstep,
                    data.fb_fix.line_length, data.fb_fix.mmio_start,
                    data.fb_fix.mmio_len, data.fb_fix.accel);
}

void Fbdev::printVariableInfo(void)
{
    SFGL_DEBUG_INFO("Variable screen info:\n"
                    "\txres: %d\n"
                    "\tyres: %d\n"
                    "\txres_virtual: %d\n"
                    "\tyres_virtual: %d\n"
                    "\tyoffset: %d\n"
                    "\txoffset: %d\n"
                    "\tbits_per_pixel: %d\n"
                    "\tgrayscale: %d\n"
                    "\tred: offset: %2d, length: %2d, msb_right: %2d\n"
                    "\tgreen: offset: %2d, length: %2d, msb_right: %2d\n"
                    "\tblue: offset: %2d, length: %2d, msb_right: %2d\n"
                    "\ttransp: offset: %2d, length: %2d, msb_right: %2d\n"
                    "\tnonstd: %d\n"
                    "\tactivate: %d\n"
                    "\theight: %d\n"
                    "\twidth: %d\n"
                    "\taccel_flags: 0x%x\n"
                    "\tpixclock: %d\n"
                    "\tleft_margin: %d\n"
                    "\tright_margin: %d\n"
                    "\tupper_margin: %d\n"
                    "\tlower_margin: %d\n"
                    "\thsync_len: %d\n"
                    "\tvsync_len: %d\n"
                    "\tsync: %d\n"
                    "\tvmode: %d\n"
                    "\n", data.fb_var.xres, data.fb_var.yres,
                    data.fb_var.xres_virtual, data.fb_var.yres_virtual,
                    data.fb_var.xoffset, data.fb_var.yoffset,
                    data.fb_var.bits_per_pixel, data.fb_var.grayscale,
                    data.fb_var.red.offset, data.fb_var.red.length,
                    data.fb_var.red.msb_right, data.fb_var.green.offset,
                    data.fb_var.green.length, data.fb_var.green.msb_right,
                    data.fb_var.blue.offset, data.fb_var.blue.length,
                    data.fb_var.blue.msb_right, data.fb_var.transp.offset,
                    data.fb_var.transp.length, data.fb_var.transp.msb_right,
                    data.fb_var.nonstd, data.fb_var.activate, data.fb_var.height,
                    data.fb_var.width, data.fb_var.accel_flags,
                    data.fb_var.pixclock, data.fb_var.left_margin,
                    data.fb_var.right_margin, data.fb_var.upper_margin,
                    data.fb_var.lower_margin, data.fb_var.hsync_len,
                    data.fb_var.vsync_len, data.fb_var.sync, data.fb_var.vmode);
}


void Fbdev::update(void)
{
    //memcpy(data.fb_mmap, buffer, bytes());
    //cout << height<<endl;
    for(int32_t y = 0; y < height; y++){
            memcpy((int32_t *)data.fb_mmap + data.width * (y + posty) + postx,
                   buffer + width * y,
                   width * sizeof(int32_t));
    }
}

void Fbdev::reDraw(SFGLDATA &arg)
{
    for(int32_t y = 0; y < arg.getHeight(); y++){
            memcpy(buffer + getWidth() * arg.getPosty() + arg.getPostx()
                            + y * getWidth(),
                   arg.buffer + arg.getWidth() * y,
                   arg.getWidth() * sizeof(int32_t));
    }
}
