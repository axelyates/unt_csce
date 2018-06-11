int main () {
  int _T0;
  int _T1;
  int q;
  int r;
  int x;
  int y;
  x = 32;
  y = 5;
  q = 0;
  r = x;
_L0:
  if (r >= y) goto _L1;
  goto _L2;
_L1:
  _T0 = q + 1;
  q = _T0;
  _T1 = r - y;
  r = _T1;
  goto _L0;
_L2:
  return 0;
}
