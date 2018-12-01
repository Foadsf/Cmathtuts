extern "C" {
void cppfunction_(float *a, float *b);
}

void cppfunction_(float *a, float *b) {
  *a = 5.0;
  *b = 6.0;
}
