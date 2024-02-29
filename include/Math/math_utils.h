#ifndef __MATHUTILS_H__
#define __MATHUTILS_H__ 1

class MathUtils {
	public:
		static float Clamp(float value, float minVal, float maxVal);

	private:
		MathUtils();
		MathUtils(const MathUtils& copy);
		~MathUtils();
};
inline MathUtils::MathUtils() {}
inline MathUtils::MathUtils(const MathUtils& copy) { *this = copy; }
inline MathUtils::~MathUtils(){}

inline float MathUtils::Clamp(float value, float minVal, float maxVal) {
	if(value >= maxVal) value = maxVal;
	if(value <= minVal) value = minVal;
	return value;
}
#endif