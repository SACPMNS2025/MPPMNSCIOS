#ifndef AVX512TOEPLITZMACROS_H_INCLUDED
#define AVX512TOEPLITZMACROS_H_INCLUDED

void _mm512_madd52_epu64(__m512i* rethi, __m512i* retlo, __m512i op1, __m512i op2)
{
	*retlo = _mm512_madd52lo_epu64(*retlo, op1, op2);
	*rethi = _mm512_madd52hi_epu64(*rethi, op1, op2);
}

#define SCHOOLBOOK(X) {\
	int64_t vecv[X/8][8];\
	for(int i = 0; i < X/8; i++)\
		_mm512_store_epi64(vecv[i], vect[i]);\
	for(int i = 0; i < X/8; i++)\
	{\
		roplo[i] = _mm512_setzero_si512();\
		rophi[i] = _mm512_setzero_si512();\
		for(int j = 0; j < X/8; j++)\
		{\
			_mm512_madd52_epu64(rophi + i, roplo + i, _mm512_set1_epi64(vecv[j][0]), _mm512_alignr_epi64(matr[X/8+i-j], matr[X/8+i-1-j],7-0));\
			_mm512_madd52_epu64(rophi + i, roplo + i, _mm512_set1_epi64(vecv[j][1]), _mm512_alignr_epi64(matr[X/8+i-j], matr[X/8+i-1-j],7-1));\
			_mm512_madd52_epu64(rophi + i, roplo + i, _mm512_set1_epi64(vecv[j][2]), _mm512_alignr_epi64(matr[X/8+i-j], matr[X/8+i-1-j],7-2));\
			_mm512_madd52_epu64(rophi + i, roplo + i, _mm512_set1_epi64(vecv[j][3]), _mm512_alignr_epi64(matr[X/8+i-j], matr[X/8+i-1-j],7-3));\
			_mm512_madd52_epu64(rophi + i, roplo + i, _mm512_set1_epi64(vecv[j][4]), _mm512_alignr_epi64(matr[X/8+i-j], matr[X/8+i-1-j],7-4));\
			_mm512_madd52_epu64(rophi + i, roplo + i, _mm512_set1_epi64(vecv[j][5]), _mm512_alignr_epi64(matr[X/8+i-j], matr[X/8+i-1-j],7-5));\
			_mm512_madd52_epu64(rophi + i, roplo + i, _mm512_set1_epi64(vecv[j][6]), _mm512_alignr_epi64(matr[X/8+i-j], matr[X/8+i-1-j],7-6));\
			_mm512_madd52_epu64(rophi + i, roplo + i, _mm512_set1_epi64(vecv[j][7]), _mm512_alignr_epi64(matr[X/8+i-j], matr[X/8+i-1-j],7-7));\
		}\
	}\
}\

#define pSCHOOLBOOK(X) {\
	int64_t vecv[X/8][8];\
	for(int i = 0; i < X/8; i++)\
		_mm512_store_epi64(vecv[i], vect[i]);\
	for(int i = 0; i < X/8; i++)\
	{\
		for(int j = 0; j < X/8; j++)\
		{\
			_mm512_madd52_epu64(rophi + i, roplo + i, _mm512_set1_epi64(vecv[j][0]), _mm512_alignr_epi64(matr[X/8+i-j], matr[X/8+i-1-j],7-0));\
			_mm512_madd52_epu64(rophi + i, roplo + i, _mm512_set1_epi64(vecv[j][1]), _mm512_alignr_epi64(matr[X/8+i-j], matr[X/8+i-1-j],7-1));\
			_mm512_madd52_epu64(rophi + i, roplo + i, _mm512_set1_epi64(vecv[j][2]), _mm512_alignr_epi64(matr[X/8+i-j], matr[X/8+i-1-j],7-2));\
			_mm512_madd52_epu64(rophi + i, roplo + i, _mm512_set1_epi64(vecv[j][3]), _mm512_alignr_epi64(matr[X/8+i-j], matr[X/8+i-1-j],7-3));\
			_mm512_madd52_epu64(rophi + i, roplo + i, _mm512_set1_epi64(vecv[j][4]), _mm512_alignr_epi64(matr[X/8+i-j], matr[X/8+i-1-j],7-4));\
			_mm512_madd52_epu64(rophi + i, roplo + i, _mm512_set1_epi64(vecv[j][5]), _mm512_alignr_epi64(matr[X/8+i-j], matr[X/8+i-1-j],7-5));\
			_mm512_madd52_epu64(rophi + i, roplo + i, _mm512_set1_epi64(vecv[j][6]), _mm512_alignr_epi64(matr[X/8+i-j], matr[X/8+i-1-j],7-6));\
			_mm512_madd52_epu64(rophi + i, roplo + i, _mm512_set1_epi64(vecv[j][7]), _mm512_alignr_epi64(matr[X/8+i-j], matr[X/8+i-1-j],7-7));\
		}\
	}\
}\

#define M1SCHOOLBOOK(X) {\
	__m512i tmp;\
	for(int i = 0; i < X/8; i++)\
		rop[i] = _mm512_setzero_si512();\
	for(int i = 0; i < X; i++)\
	{\
		tmp = _mm512_set1_epi64(((int64_t*)vect)[i]);\
		for(int j = 0; j < X/8; j++)\
		{\
			rop[j] = _mm512_madd52lo_epu64(rop[j], tmp, matr[X - 1 - i + 8*j]);\
		}\
	}\
}

#endif
