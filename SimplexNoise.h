#ifndef _SIMPLEXNOISE_SNOISE3_H
#define _SIMPLEXNOISE_SNOISE3_H

typedef struct {
    int offsets[8][2][4];
    unsigned char *perm, *mperm; // perm mod 12
} NoiseContext;

#ifdef __cplusplus
extern "C" {
#endif
    
extern void permsetup(NoiseContext *nc);
extern float noise3(float x, float y, float z, NoiseContext *nc);
    
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
class SimplexNoise
{
public:
    SimplexNoise()
    {
        permsetup(&m_noiseContext);
    }
    
    float noise(float x, float y, float z)
    {
        return ::noise3(x, y, z, &m_noiseContext);
    }
    
private:
    NoiseContext m_noiseContext;
};
#endif

#endif