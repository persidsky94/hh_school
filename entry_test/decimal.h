int get_numeral(int r, int k) //returns k-th numeral from the end of the number r in decimal number system
{
  return ((r%int(pow(10,k))) - (r%int(pow(10,k-1))))/int(pow(10,k-1)); 
}

int decimal_length(int d)
{
  if (d <= 0) 
  {
    return -1;
  }
  int w = 1;
  while (d >= int(pow(10,w)))
  {
    w += 1;
  }
  return w;
}
