
extern "C" {
    void testret_( float *mat);
    }


void testret_( float *mat ) 
{
    *mat = *mat + 1;
}

