#ifndef RECTANGLE
#define RECTANGLE

// Rectangle class declaration
class Rectangle
{
   private:
      float Width;
      float Length;
      float Area;
   public:
      void SetData (float, float);
      void CalcArea (void);
      float GetWidth(void);
      float GetLength(void);
      float GetArea(void);
};
#endif
