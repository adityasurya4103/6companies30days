class Solution {
public:
    double _radius, _x_center, _y_center;
    Solution(double radius, double x_center, double y_center) {
        _radius=radius;
        _x_center=x_center;
        _y_center=y_center;
    }
    vector<double> randPoint() {
        long r1, r2;
        do
        {
            r1=rand()-RAND_MAX/2, r2=rand()-RAND_MAX/2;
        }
        while((r1*r1+r2*r2)>((long)RAND_MAX)*(long)RAND_MAX/4);
        double x, y;
        x=_x_center+_radius*r1/(RAND_MAX/2);
        y=_y_center+_radius*r2/(RAND_MAX/2);
        return vector<double>{x, y};
    }
}
