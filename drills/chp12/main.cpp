#include <iostream>
#include "../../include/Simple_window.h"
#include "../../include/Graph.h"
int main() {
    try {
    Simple_window w(Point(100,100), 800,600, "1");
    w.wait_for_button();
    Axis xa {Axis::x, Point{200,300}, 280, 10, "x axis"};
    w.attach(xa);
    w.set_label("2");
    w.wait_for_button();
    Axis ya {Axis::y, Point{200,300}, 280, 10, "y axis"};
    ya.set_color(Color::cyan);
    ya.label.set_color(Color::dark_red); // choose a color for the text
    w.attach(ya);
    w.set_label("3");
    w.wait_for_button();
    Function sine {sin,0,100,Point{200,300},1000,50,50}; // sine curve
    w.attach(sine);
    w.set_label("4");
    w.wait_for_button();
    sine.set_color(Color::blue); // we changed our mind about sine’s color
    Polygon poly;
    poly.add(Point{300,200});
    poly.add(Point{350,100});
    poly.add(Point{400,200}); // a polygon; a Polygon is a kind of Shape
    // three points make a triangle
    poly.set_color(Color::red);
    poly.set_style(Line_style::dash);
    w.attach(poly);
    w.set_label("5");
    w.wait_for_button();
    Rectangle r {Point{200,200}, 100, 50};
    w.attach(r);
    w.set_label("6");
    w.wait_for_button();
    Closed_polyline poly_rect;
    poly_rect.add(Point{100,50});
    poly_rect.add(Point{200,50});
    poly_rect.add(Point{200,100});
    poly_rect.add(Point{100,100});
    w.attach(poly_rect);
    poly_rect.add(Point{50,75});
    w.set_label("7");
    w.wait_for_button();
    r.set_fill_color(Color::yellow);
    // color the inside of the rectangle
    poly.set_style(Line_style(Line_style::dash,4));
    poly_rect.set_style(Line_style(Line_style::dash,2));
    poly_rect.set_fill_color(Color::yellow);
    w.set_label("8");
    w.wait_for_button();
    Text t {Point{300, 300}, "Hello, graphical world!"};
    w.attach(t);
    w.set_label("9");
    w.wait_for_button();
    t.set_font(Font::helvetica_bold);
    t.set_font_size(20);
    w.set_label("10");
    w.wait_for_button();
    Image ii {Point(100,50),"badge.jpg"};
    w.attach(ii);
    w.set_label("11");
    w.wait_for_button();
    ii.move(100,400);
    w.set_label("12");
    w.wait_for_button();
    Circle c {Point{100,200},50};
    Ellipse e {Point{100,200}, 75,25};
    e.set_color(Color::blue);
    Mark m {Point(100,200),'x'};
    ostringstream oss;
    oss << "screen size: " << x_max() << "*" << y_max()
    << "; window size: " << w.x_max() << "*" << w.y_max();
    Text sizes {Point{100,20},oss.str()};
    Image cal {Point{225,225},"badge.jpg"};
    cal.set_mask(Point{40,40},200,150);
    // 320*240-pixel gif
    // display center part of image12.8
    w.attach(c);
    w.attach(m);
    w.attach(e);
    w.attach(sizes);
    w.attach(cal);
    w.set_label("13");
    w.wait_for_button();
    }
    catch(...) {
        std::cout<<"Something went wront!";
        return 1;
    }
}