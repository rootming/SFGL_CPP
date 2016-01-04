#include "image.h"
#include <png.h>

SFGLImage::SFGLImage(string filename, SFGLData *parent)
{
    buffer = NULL;
    loadFile(filename);
    if(parent != 0)
        parent->addChild(this);

}


int SFGLImage::loadImageFromPNG(string filename)
{
    int x = 0;
    int y = 0;
    //	int passes_nr = 0;
    volatile uint64_t seek = 0;
    int32_t tmp;

    FILE *fp = NULL;

    unsigned char *src = NULL;

    //Image* image = NULL;
    png_structp png_ptr = NULL;
    png_infop info_ptr = NULL;
    png_bytep * row_pointers = NULL;

    if((fp = fopen(filename.c_str(), "rb")) == NULL){
        printf("%s: open %s failed.\n", __func__, filename.c_str());
        return EXIT_FAILURE;
    }

    if((png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL,
                                         NULL)) == NULL)
    {
        fclose(fp);
        return EXIT_FAILURE;
    }

    if((info_ptr = png_create_info_struct(png_ptr)) == NULL){
        fclose(fp);
        return EXIT_FAILURE;
    }

#ifdef PNG_SETJMP_SUPPORTED
    setjmp(png_jmpbuf(png_ptr));
#endif

    png_init_io(png_ptr, fp);

    memset(info_ptr, 0x00, sizeof(*info_ptr));
    png_read_info(png_ptr, info_ptr);

    width = info_ptr->width;
    height = info_ptr->height;
    resize(width, height);
    //SFGL_Surface *surface = CreatSurfaceRGBA(w, h);
    //	passes_nr = png_set_interlace_handling(png_ptr);
    png_set_interlace_handling(png_ptr);
    png_read_update_info(png_ptr, info_ptr);

#ifdef PNG_SETJMP_SUPPORTED
    setjmp(png_jmpbuf(png_ptr));
#endif

    row_pointers = (png_bytep*)calloc(1, height * sizeof(png_bytep));
    for(y = 0; y < height; y++){
        row_pointers[y] = (png_byte*)calloc(1, info_ptr->rowbytes);
    }
    png_read_image(png_ptr, row_pointers);

    if(info_ptr->color_type == PNG_COLOR_TYPE_RGBA){
        for(y = 0; y < height; y++){
            src = row_pointers[y];
            for(x = 0; x < width; x++){
                tmp = src[0] << Fbdev::redOffset |
                                src[1] << Fbdev::greenOffset |
                                          src[2] << Fbdev::blueOffset |
                                                    src[3] << Fbdev::alphaOffset;
                memcpy((int32_t *)buffer + seek, &tmp, sizeof(int32_t));
                seek = x + y * width;
                src += 4;
            }
        }
    }


    //    #if PNG_LIBPNG_VER > 10399
    //                png_byte red = png_ptr->trans_color.red & 0xff;
    //                png_byte green = png_ptr->trans_color.green & 0xff;
    //                png_byte blue = png_ptr->trans_color.blue & 0xff;
    //    #else
    //                png_byte red = png_ptr->trans_values.red & 0xff;
    //                png_byte green = png_ptr->trans_values.green & 0xff;
    //                png_byte blue = png_ptr->trans_values.blue & 0xff;
    //    #endif


    for(y = 0; y < height; y++){
        free(row_pointers[y]);
    }
    free(row_pointers);
    png_destroy_read_struct(&png_ptr, &info_ptr, NULL);

    fclose(fp);
    return EXIT_SUCCESS;


}

int SFGLImage::loadFile(string filename)
{
    loadImageFromPNG(filename);
    return EXIT_SUCCESS;
}
