class Zone
{
    protected:
    int x;
    int y;
    bool pellet;
    // w & h

    protected:
    Zone();
    Zone(int coord_x, int coord_y, bool has_pellet);
    ~Zone();
    
};