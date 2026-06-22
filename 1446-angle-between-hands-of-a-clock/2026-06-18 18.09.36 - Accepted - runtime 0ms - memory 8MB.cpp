class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour = hour%12;
        double pos1 = 6*minutes;
        double pos2 = 30*(hour+minutes/60.0);
        double angle = abs(pos1 -pos2);
        return angle<180?angle:360-angle;
    }
};