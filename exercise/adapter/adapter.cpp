struct Square
{
  int side{ 0 };


  explicit Square(const int side)
    : side(side)
  {
  }
};

struct Rectangle
{
  virtual int width() const = 0;
  virtual int height() const = 0;

  int area() const
  {
    return width() * height();
  }
};

struct SquareToRectangleAdapter : Rectangle
{
  SquareToRectangleAdapter(const Square& square)
  {
      h = square.side;
      w = square.side;
  }
  virtual int width() const{
    return w;
  }
  virtual int height() const{
      return h;
  }
  private:
  int h = 0;
  int w = 0;
}; 
