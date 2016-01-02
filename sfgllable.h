#ifndef SFGLLABLE_H
#define SFGLLABLE_H
#include "surface.h"
#define DEF_FONT "def.ttf"
class SFGLLable : public SFGLSurface
{
public:
  SFGLLable(wstring str = L"");
  enum SFGLENCODE{ GB2312, UNICODE };
  void setFont(string &path) { font = path; }
  void setFontSize(uint32_t size) { fontSize = size; }
  void setFontColor(SFGLColor color){ strColor = color; }
  void setBlank(uint32_t dis) { blank = dis; }
  void setCode(SFGLENCODE tcode){ code = tcode; }
  int initString();

private:
  string font;
  wstring data;
  int blank;
  int code;
  uint32_t fontSize;
  SFGLColor strColor;

  wchar_t *gb2un(wstring &str);
  int blitChar(wchar_t fonts_format, uint32_t x, uint32_t y, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
  void blitStr(wstring &str, uint32_t x, uint32_t y, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
};

#endif // SFGLLABLE_H
