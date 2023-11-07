struct Time {
    int hour, minute;
    double second;

    void increment(double);
    Time(int, int, double);
    Time(double);
    Time(int, int, int);
    std::string to_string() const;
};