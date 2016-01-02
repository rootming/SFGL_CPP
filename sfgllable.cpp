#include "sfgllable.h"
#include <freetype2/ft2build.h>
#include <freetype2/freetype.h>
#include <freetype2/fttypes.h>
#include <freetype2/ftglyph.h>
#include <iconv.h>
#include <wchar.h>
#include "debug.h"
#include "basedraw.h"


#include <iconv.h>
SFGLLable::SFGLLable(wstring str)
{
    font = DEF_FONT;
    fontSize = 20;
    strColor = {255, 255, 255, 255};
    blank = 10;
    data = str;
    code = UNICODE;
    initString();

}

int SFGLLable::initString()
{
    int tw = fontSize * data.length() + blank * data.length();
    int th = fontSize;
    resize(tw, th);
    blitStr(data, 0, 0, strColor.r, strColor.g, strColor.b, strColor.a);
    return 0;
}

wchar_t *SFGLLable::gb2un(wstring  &str)
{
  int i = 0;
  wchar_t *temp = new wchar_t[str.length()];
  size_t src_len = str.length();
  uint8_t *dst = new uint8_t[str.length()];

  size_t dst_len = sizeof(dst);
  const wchar_t *in = str.c_str();
  iconv_t cd;
  uint8_t *out = dst;
  switch(code){
    case GB2312:
      cd = iconv_open("UCS-2", "GB2312");
      break;
    case UNICODE:
      cd = iconv_open("UCS-2", "UTF-8");
      break;
    default:
      SFGL_DEBUG_WORRY("Not support\n");
      exit(1);
  }
  iconv(cd, (char **)&in, &src_len, (char **)&out, &dst_len);
  iconv_close(cd);

  for (i = 0; dst[i] != 0; i++) {
      if (i & 1)
        temp[i / 2] |= (dst[i]);
      else
        temp[i / 2] |= (dst[i] << 8);
    }

  return (temp);
}

int SFGLLable::blitChar(wchar_t fonts_format, uint32_t x, uint32_t y, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
  FT_Error           error = 0;
  FT_Bitmap          bitmap;
  FT_BitmapGlyph     bitmap_glyph;
  FT_Glyph           glyph;
  FT_Library  FT_Lib;
  FT_Face  FT_Face;
  uint32_t i , j , k ;

  error = FT_Init_FreeType(&FT_Lib);

  if (error) {
      FT_Lib = 0 ;
      SFGL_DEBUG_ERROR("Init Freetype Lib\n");
      return -1;
    }

  error = FT_New_Face(FT_Lib, font.c_str(), 0 , &FT_Face);

  if ( error == FT_Err_Unknown_File_Format ) {
      SFGL_DEBUG_ERROR("FT_UNKNOWN_FILE_FORMAT\n");
      return -1;
    } else if (error) {
      SFGL_DEBUG_ERROR("FT_OPEN_FILE_ERROR\n");
      return -1;
    }

  FT_Set_Pixel_Sizes(FT_Face, 0, fontSize);

  FT_Load_Glyph(FT_Face, FT_Get_Char_Index(FT_Face, fonts_format), FT_LOAD_DEFAULT);

  error = FT_Get_Glyph(FT_Face -> glyph, &glyph);

  if ( !error) {

      FT_Glyph_To_Bitmap(&glyph, FT_RENDER_MODE_LIGHT, 0 , 1 );

      bitmap_glyph = (FT_BitmapGlyph)glyph;

      bitmap = bitmap_glyph -> bitmap;

//      uint32_t pixel =  tmp = strColor.r << Fbdev::redOffset |
//                                        strColor.g << Fbdev::greenOffset |
//                                                  strColor.b << Fbdev::blueOffset |
//                                                            strColor.a << Fbdev::alphaOffset;

      for ( i = 0, k = 0; i < bitmap.rows; ++i) {
          for ( j = 0 ; j < bitmap.width; ++j,++k) {
              if ( bitmap.buffer[i * bitmap.width + j] != 0 ) {
                  SFGLDraw::drawPixel(*this , x + j, y + i, r, g, b, a);
                  //DrawPixelB(surface, x+j, y+i,r,g,b,a);
                   //memcpy((int32_t *)buffer + , &tmp, sizeof(int32_t));
                  //cout<<"*";
                } else {
                  //cout<<" ";
                }
            }
                  //cout<<"\n";
        }

      FT_Done_Glyph(glyph);
      glyph = NULL;

    }

  FT_Done_Face(FT_Face);
  FT_Face = NULL;

  FT_Done_FreeType(FT_Lib);
  FT_Lib = NULL;

  return 0;
}

void SFGLLable::blitStr(wstring &str, uint32_t x, uint32_t y, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
  uint32_t i,j,k,end;
  uint32_t str_len = str.length();
  //wchar_t *decchar;;

  //decchar = gb2un(str);
  //printf("%ls",decchar);
  end = (blank + fontSize) * (str_len - 1) ;
  j = y;
  for(i = x, k = 0; i <= end; i += (fontSize + blank), k++){
      blitChar(str[k], i, j, r, g, b, a);
    }
}
