// Exercise 16.9

/*

Write the following functions. (The color structure is defined in Exercise 8.)
    (a) struct color make_color(int red, int green, int blue);
    Returns a color structure containing the specified red, green, and blue values. If any argu-
    ment is less than zero, the corresponding member of the structure will contain zero instead.
    If any argument is greater than 255, the corresponding member of the structure will contain
    255.
    
    (b) int getRed(struct color c);
        Returns the value of c's red member.
    
    (c) bool equal_color(struct color color1, struct color color2);
        Returns true if the corresponding members of color1 and color2 are equal.
    
        
    (d) struct color brighter(struct color c);
        Returns a color structure that represents a brighter version of the color c. The structure is
        identical to c, except that each member has been divided by 0.7 (with the result truncated to
        an integer). However, there are three special cases: (1) If all members of c are zero, the
        function returns a color whose members all have the value 3. (2) If any member of c is
        greater than 0 but less than 3, it is replaced by 3 before the division by 0.7. (3) If dividing by
        0.7 causes a member to exceed 255, it is reduced to 255.
    
    (e) struct color darker(struct color c);
        Returns a color structure that represents a darker version of the color c. The structure is
        identical to c, except that each member has been multiplied by 0.7 (with the result truncated
        to an integer).

*/

#include <stdio.h>
#include <stdbool.h>

struct color {
    int red;
    int green;
    int blue;
};

static inline int getRed(struct color c) { return c.red; }
static inline int getGreen(struct color c) { return c.green; }
static inline int getBlue(struct color c) { return c.blue; }

static inline bool equal_color(struct color c1, struct color c2){
    return c1.red == c2.red && 
        c1.green == c2.green && 
        c1.blue == c2.blue;
}

struct color make_color(int red, int green, int blue);
struct color brighter(struct color c);
struct color darker(struct color c);

int main(void){
    struct color c1 = make_color(255, 0, 0);
    struct color c2 = make_color(0, 255, 0);
    struct color c3 = make_color(0, 0, 255);
    struct color c4 = make_color(255, 255, 0);
    
    printf("Color 1: %d %d %d\n", c1.red, c1.green, c1.blue);
    printf("Color 2: %d %d %d\n", c2.red, c2.green, c2.blue);
    printf("Color 3: %d %d %d\n", c3.red, c3.green, c3.blue);
    printf("Color 4: %d %d %d\n", c4.red, c4.green, c4.blue);

    struct color c5 = brighter(c1);
    struct color c6 = darker(c2);
    
    printf("Brighter Color 1: %d %d %d\n", c5.red, c5.green, c5.blue);
    printf("Darker Color 2: %d %d %d\n", c6.red, c6.green, c6.blue);

    printf("Is Darker Color 3 equal to Brighter Color 4? %d\n", 
        equal_color(darker(c3), brighter(c4)));
    
    return 0;
}

struct color make_color(int red, int green, int blue){

    return (struct color){
        .red = red < 0 ? 0 : red > 255 ? 255 : red,
        .green = green < 0 ? 0 : green > 255 ? 255 : green,
        .blue = blue < 0 ? 0 : blue > 255 ? 255 : blue
    };
}

struct color brighter(struct color c){
    if(!c.red  && !c.green && !c.blue){
        return (struct color){
            .red = 3,
            .green = 3,
            .blue = 3
        };
    }

    int red = (c.red > 0 && c.red < 3 ? 3 : c.red) * 10 / 7;
    int green = (c.green > 0 && c.green < 3 ? 3 : c.green) * 10 / 7;
    int blue = (c.blue > 0 && c.blue < 3 ? 3 : c.blue) * 10 / 7;
    
    return (struct color){
        .red = red > 255 ? 255 : red,
        .green = green > 255 ? 255 : green,
        .blue = blue > 255 ? 255 : blue
    };
}

struct color darker(struct color c){
    return (struct color){
        .red = c.red * 7 / 10,
        .green = c.green * 7 / 10,
        .blue = c.blue * 7 / 10
    }; 
}