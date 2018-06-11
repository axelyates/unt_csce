#include "rectang.h"

// SetData copies the argument W to private member Width
// and L to private member Length.
void Rectangle::SetData(float W, float L)
{
   Width = W;
   Length = L;
}

//CalcArea multiplies the private members Width and Length.
//The result is stored in the private member Area.
void Rectangle::CalcArea(void)
{
   Area = Width * Length;
}

// GetWidth returns the value in the private member Width.
float Rectangle::GetWidth(void)
{
   return Width;
}

// GetLength returns the value in the private member Length.
float Rectangle::GetLength(void)
{
   return Length;
}

//GetArea returns the value in the private member Area.
float Rectangle::GetArea(void)
{
   return Area;
}