#include <cmath>
#include <array>

#include "tweening.h"

namespace tweening
{

#ifndef PI
#define PI 3.1415926545
#endif

    double linear(double t)
    {
        return t;
    }

    double easeInSine(double t)
    {
        return 1 - cos((t * PI) / 2);
        // return 1 - Math.cos((x * Math.PI) / 2);
    }

    double easeOutSine(double t)
    {
        return sin((t * PI) / 2);
        //return Math.sin((x * Math.PI) / 2);
    }

    double easeInOutSine(double t)
    {
        return -(cos(PI * t) - 1) / 2;
        // return -(Math.cos(Math.PI * x) - 1) / 2;
    }

    double easeInQuad(double t)
    {
        return t * t;
        // return x * x;
    }

    double easeOutQuad(double t)
    {
        return 1 - (1 - t) * (1 - t);
        // return 1 - (1 - x) * (1 - x);
    }

    double easeInOutQuad(double t)
    {
        return t < 0.5 ? 2 * t * t : 1 - pow(-2 * t + 2, 2) / 2;
        // return x < 0.5 ? 2 * x * x : 1 - Math.pow(-2 * x + 2, 2) / 2;
    }

    double easeInCubic(double t)
    {
        return t * t * t;
        // return x * x * x;
    }

    double easeOutCubic(double t)
    {
        return 1 - pow(1 - t, 3);
        // return 1 - Math.pow(1 - x, 3);
    }

    double easeInOutCubic(double t) {
        return t < 0.5 ? 4 * t * t * t : 1 - pow(-2 * t + 2, 3) / 2;
        // return x < 0.5 ? 4 * x * x * x : 1 - Math.pow(-2 * x + 2, 3) / 2;
    }

    double easeInQuart(double t)
    {
        return t * t * t * t;
        // return x * x * x * x;
    }

    double easeOutQuart(double t)
    {
        return 1 - pow(1 - t, 4);
        // return 1 - Math.pow(1 - x, 4);
    }

    double easeInOutQuart(double t)
    {
        return t < 0.5 ? 8 * t * t * t * t : 1 - pow(-2 * t + 2, 4) / 2;
        // return x < 0.5 ? 8 * x * x * x * x : 1 - Math.pow(-2 * x + 2, 4) / 2;
    }

    double easeInQuint(double t)
    {
        return t * t * t * t * t;
        // return x * x * x * x * x;
    }

    double easeOutQuint(double t)
    {
        return 1 - pow(1 - t, 5);
        // return 1 - Math.pow(1 - x, 5);
    }

    double easeInOutQuint(double t)
    {
        return t < 0.5 ? 16 * t * t * t * t * t : 1 - pow(-2 * t + 2, 5) / 2;
        // return x < 0.5 ? 16 * x * x * x * x * x : 1 - Math.pow(-2 * x + 2, 5) / 2;
    }

    double easeInExpo(double t)
    {
        return t == 0 ? 0 : pow(2, 10 * t - 10);
        // return x === 0 ? 0 : Math.pow(2, 10 * x - 10);
    }

    double easeOutExpo(double t)
    {
        return t == 1 ? 1 : 1 - pow(2, -10 * t);
        // return x === 1 ? 1 : 1 - Math.pow(2, -10 * x);
    }

    double easeInOutExpo(double t)
    {
        return t == 0? 0: t == 1? 1: t < 0.5 ? pow(2, 20 * t - 10) / 2: (2 - pow(2, -20 * t + 10)) / 2;
        // return x == 0? 0: x === 1? 1: x < 0.5 ? Math.pow(2, 20 * x - 10) / 2: (2 - Math.pow(2, -20 * x + 10)) / 2;
    }

    double easeInCirc(double t)
    {
        return 1 - sqrt(1 - pow(t, 2));
        // return 1 - Math.sqrt(1 - Math.pow(x, 2));
    }

    double easeOutCirc(double t)
    {
        return sqrt(1 - pow(t - 1, 2));
        // return Math.sqrt(1 - Math.pow(x - 1, 2));
    }

    double easeInOutCirc(double t)
    {
        return t < 0.5 ? (1 - sqrt(1 - pow(2 * t, 2))) / 2 : (sqrt(1 - pow(-2 * t + 2, 2)) + 1) / 2;
        // return x < 0.5 ? (1 - Math.sqrt(1 - Math.pow(2 * x, 2))) / 2 : (Math.sqrt(1 - Math.pow(-2 * x + 2, 2)) + 1) / 2;
    }

    double easeInBack(double t)
    {
        return (2.70158) * t * t * t - (1.70158) * t * t;
        // return (2.70158) * x * x * x - (1.70158) * x * x;
    }

    double easeOutBack(double t)
    {
        return 1 + (2.70158) * pow(t - 1, 3) + (1.70158) * pow(t - 1, 2);
        // return 1 + (2.70158) * Math.pow(x - 1, 3) + (1.70158) * Math.pow(x - 1, 2);
    }

    double easeInOutBack(double t)
    {
        const double c1 = 1.70158;
        const double c2 = c1 * 1.525;
        
        return t < 0.5
        ? (pow(2 * t, 2) * ((c2 + 1) * 2 * t - c2)) / 2
        : (pow(2 * t - 2, 2) * ((c2 + 1) * (t * 2 - 2) + c2) + 2) / 2;

        // const c1 = 1.70158;
        // const c2 = c1 * 1.525;
        // return x < 0.5
        // ? (Math.pow(2 * x, 2) * ((c2 + 1) * 2 * x - c2)) / 2
        // : (Math.pow(2 * x - 2, 2) * ((c2 + 1) * (x * 2 - 2) + c2) + 2) / 2;
    }

    double easeInElastic(double t)
    {
        const double c4 = (2 * PI) / 3;
        return t == 0 ? 0 : t == 1 ? 1 : -pow(2, 10 * t - 10) * sin((t * 10 - 10.75) * c4);

        // const c4 = (2 * Math.PI) / 3;
        // return x === 0 ? 0 : x === 1 ? 1 : -Math.pow(2, 10 * x - 10) * Math.sin((x * 10 - 10.75) * c4);
    }

    double easeOutElastic(double t)
    {
        const double c4 = (2 * PI) / 3;
        return t == 0 ? 0 : t == 1 ? 1 : pow(2, -10 * t) * sin((t * 10 - 0.75) * c4) + 1;

        // const c4 = (2 * Math.PI) / 3;
        // return x === 0 ? 0 : x === 1 ? 1 : Math.pow(2, -10 * x) * Math.sin((x * 10 - 0.75) * c4) + 1;
    }

    double easeInOutElastic(double t)
    {
        const double c5 = (2 * PI) / 4.5;
        return t == 0 ? 0 : t == 1 ? 1 : t < 0.5
        ? -(pow(2, 20 * t - 10) * sin((20 * t - 11.125) * c5)) / 2
        : (pow(2, -20 * t + 10) * sin((20 * t - 11.125) * c5)) / 2 + 1;

        // const c5 = (2 * Math.PI) / 4.5;
        // return x === 0 ? 0 : x === 1 ? 1 : x < 0.5
        // ? -(Math.pow(2, 20 * x - 10) * Math.sin((20 * x - 11.125) * c5)) / 2
        // : (Math.pow(2, -20 * x + 10) * Math.sin((20 * x - 11.125) * c5)) / 2 + 1;
    }

    double easeOutBounce(double t)
    {
        const double n1 = 7.5625;
        const double d1 = 2.75;

        if (t < 1 / d1) {
            return n1 * t * t;
        } else if (t < 2 / d1) {
            return n1 * (t -= 1.5 / d1) * t + 0.75;
        } else if (t < 2.5 / d1) {
            return n1 * (t -= 2.25 / d1) * t + 0.9375;
        } else {
            return n1 * (t -= 2.625 / d1) * t + 0.984375;
        }

        // const n1 = 7.5625;
        // const d1 = 2.75;

        // if (x < 1 / d1) {
        //     return n1 * x * x;
        // } else if (x < 2 / d1) {
        //     return n1 * (x -= 1.5 / d1) * x + 0.75;
        // } else if (x < 2.5 / d1) {
        //     return n1 * (x -= 2.25 / d1) * x + 0.9375;
        // } else {
        //     return n1 * (x -= 2.625 / d1) * x + 0.984375;
        // }
    }

    double easeInBounce(double t)
    {
        return 1 - easeOutBounce(1 - t);
        // return 1 - easeOutBounce(1 - x);
    }

    double easeInOutBounce(double t)
    {
        return t < 0.5
        ? (1 - easeOutBounce(1 - 2 * t)) / 2
        : (1 + easeOutBounce(2 * t - 1)) / 2;

        // return x < 0.5
        // ? (1 - easeOutBounce(1 - 2 * x)) / 2
        // : (1 + easeOutBounce(2 * x - 1)) / 2;
    }

    constexpr std::array<tweening::easingFunction, 31> easingTable = {
        linear,
        easeInSine,
        easeOutSine,
        easeInOutSine,
        easeInQuad,
        easeOutQuad,
        easeInOutQuad,
        easeInCubic,
        easeOutCubic,
        easeInOutCubic,
        easeInQuart,
        easeOutQuart,
        easeInOutQuart,
        easeInQuint,
        easeOutQuint,
        easeInOutQuint,
        easeInExpo,
        easeOutExpo,
        easeInOutExpo,
        easeInCirc,
        easeOutCirc,
        easeInOutCirc,
        easeInBack,
        easeOutBack,
        easeInOutBack,
        easeInElastic,
        easeOutElastic,
        easeInOutElastic,
        easeInBounce,
        easeOutBounce,
        easeInOutBounce};

    tweening::easingFunction getEasingFunction(tweening::easing_functions f)
    {
        return (static_cast<size_t>(f) < easingTable.size()) ? easingTable[f] : nullptr;
    }

}