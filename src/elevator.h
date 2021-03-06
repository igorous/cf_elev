#include <chrono>
#include <iostream>

#include "config.h"
#include "blocking_set.h"
#include "util.h"

using namespace std;

namespace NElev {

class Elevator {
public:
  using FloorValueType = long long;

  Elevator(Config cfg, ostream& out);

  void run();
  void call(FloorValueType next_floor);

private:
  void render_status();
  void doors_open();

private:

  BlockingSet<FloorValueType> next_floors_;
  Config cfg_;
  FloorValueType cur_floor_;
  float floor_time_gap_;

  ostream& out_;
};

} // NElev

