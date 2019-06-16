#include <string>
using namespace std;
struct Renderer
{
    virtual string what_to_render_as(string& name) const = 0;
};

struct VectorRenderer: Renderer
{
    virtual string what_to_render_as(string& name) const
    {
        return "Drawing " + name + " as lines";
    }
};
struct RasterRenderer: Renderer
{
    virtual string what_to_render_as(string& name) const
    {
        return "Drawing " + name + " as pixels";
    }
};
struct Shape
{
    string name;
    Shape(const Renderer& renderer)
    :str_renderer(renderer)
    {
    }
    string str()
    {
        return str_renderer.what_to_render_as(name);
    }
    const Renderer& str_renderer;
};

struct Triangle : Shape
{
    Triangle(const Renderer& renderer)
    :Shape(renderer)
    {
        name = "Circle";
    }

};

struct Square : Shape
{
    Square(const Renderer& renderer)
    :Shape(renderer)
    {
        name = "Square";
    }

};

struct VectorSquare : Square
{
    string str() const
    {
        return "Drawing " + name + " as lines";
    }
};

struct RasterSquare : Square
{
    string str() const
    {
        return "Drawing " + name + " as pixels";
    }
};
