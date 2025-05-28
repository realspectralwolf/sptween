#include <cmath>

namespace tweening
{

	inline float clamp(float x, float min, float max)
	{
		return std::fmin(std::fmax(x, min), max);
	}

	enum easing_functions
	{
		Linear,
		EaseInSine,
		EaseOutSine,
		EaseInOutSine,
		EaseInQuad,
		EaseOutQuad,
		EaseInOutQuad,
		EaseInCubic,
		EaseOutCubic,
		EaseInOutCubic,
		EaseInQuart,
		EaseOutQuart,
		EaseInOutQuart,
		EaseInQuint,
		EaseOutQuint,
		EaseInOutQuint,
		EaseInExpo,
		EaseOutExpo,
		EaseInOutExpo,
		EaseInCirc,
		EaseOutCirc,
		EaseInOutCirc,
		EaseInBack,
		EaseOutBack,
		EaseInOutBack,
		EaseInElastic,
		EaseOutElastic,
		EaseInOutElastic,
		EaseInBounce,
		EaseOutBounce,
		EaseInOutBounce
	};

	typedef double (*easingFunction)(double);

	easingFunction getEasingFunction(easing_functions function);

	// ✅ Tween struct
	struct tween
	{
		float from = 0.0f;
		float to = 1.0f;
		float duration = 1.0f; // in seconds
		float elapsed = 0.0f;  // time passed
		easingFunction easing;

		tween(float from, float to, float duration, easing_functions easingType)
			: from(from), to(to), duration(duration),
			  easing(getEasingFunction(easingType)) {}

		void step(float dt)
		{
			elapsed = std::fmin(elapsed + dt, duration);
		}

		float progress() const
		{
			return (elapsed / duration);
		}

		float value() const
		{
			float p = progress();
			return from + (to - from) * easing(p);
		}

		void set_progress(float t)
		{
			elapsed = t * duration;
		}

		bool done() const
		{
			return elapsed >= duration;
		}
	};

}