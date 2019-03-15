// Copyright (c) 2017 Computer Vision Center (CVC) at the Universitat Autonoma
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#include "carla/road/Road.h"
#include "carla/road/Lane.h"
#include "carla/road/MapData.h"
#include "carla/Logging.h"

#include <boost/optional.hpp>

namespace carla {
namespace road {

  const MapData *Road::GetMap() const {
    return _map_data;
  }

  RoadId Road::GetId() const {
    return _id;
  }

  std::string Road::GetName() const {
    return _name;
  }

  float Road::GetLength() const {
    return _length;
  }

  bool Road::IsJunction() const {
    return _is_junction;
  }

  JuncId Road::GetJunction() const {
    return _junction_id;
  }

  std::vector<const Road *> Road::GetNexts() const {
    std::vector<const Road *> vec;
    for (auto &&next : _nexts) {
      vec.emplace_back(_map_data->GetRoad(next));
    }
    return vec;
  }

  std::vector<const Road *> Road::GetPrevs() const {
    std::vector<const Road *> vec;
    for (auto &&prev : _prevs) {
      vec.emplace_back(_map_data->GetRoad(prev));
    }
    return vec;
  }

  /*
  const Lane *Road::GetLane(const LaneId id, const float s) const {
    const auto sections = _lane_sections.GetReverseSubset(s);
    if (sections.empty()) {
      log_warning("road", id, "in distance s", s, "not found");
      return nullptr;
    }
    return sections.begin()->GetLane(id);
  }
  */

} // road
} // carla