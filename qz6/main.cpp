#include <iostream>
using namespace std;

class Clock {
	public:
		int Hour;
		int Minute;
		int Second;
		string meridian;
		Clock(int h, int m, int s, string mer) {
			Hour = h;
			Minute = m;
			Second = s;
			meridian = mer;
		}
		void display() {
			cout << Hour << ":" << Minute << ":" << Second << " " << meridian << endl;
		}
};

class StandardClock : Clock {
	private:
		string Chinese_meridian;
	public:
		StandardClock(int h, int m, int s, string mer) : Clock(h, m, s, mer) {
			if(mer == "AM") {
				Chinese_meridian = "上午";
			} else {
				Chinese_meridian = "下午";
			}
		}
		void display() {
			cout << Chinese_meridian << " " << Hour << ":" << Minute << ":" << Second << endl;
		}
		
};

class MilitaryClock : Clock {
	private:
		int MC_h;
	public:
		MilitaryClock(int h, int m, int s, string mer) : Clock(h, m, s, mer) {
			if(mer == "PM") {
				MC_h = h + 12;
			}
		}
		void display() {
			cout << MC_h << ":" << Minute << ":" << Second << endl;
		}
		
};

int main(void) {
	Clock cc(10, 25, 43, "AM");
	StandardClock sc(10, 10, 43, "AM");
	MilitaryClock mc(10, 25, 43, "PM");
	cc.display();
	sc.display();
	mc.display();

	return 0;
}
