/**********************************************************************
 *  Copyright (c) 2008-2015, Alliance for Sustainable Energy.
 *  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 **********************************************************************/

#include "SurfacePropertyConvectionCoefficientsMultipleSurface.hpp"
#include "SurfacePropertyConvectionCoefficientsMultipleSurface_Impl.hpp"

// TODO: Check the following class names against object getters and setters.
#include "Schedule.hpp"
#include "Schedule_Impl.hpp"
#include "UserConvectionModels.hpp"
#include "UserConvectionModels_Impl.hpp"
#include "Schedule.hpp"
#include "Schedule_Impl.hpp"
#include "UserConvectionModels.hpp"
#include "UserConvectionModels_Impl.hpp"
#include "../../model/ScheduleTypeLimits.hpp"
#include "../../model/ScheduleTypeRegistry.hpp"

#include <utilities/idd/IddFactory.hxx>
#include <utilities/idd/IddEnums.hxx>
#include <utilities/idd/OS_SurfaceProperty_ConvectionCoefficients_MultipleSurface_FieldEnums.hxx>

#include "../utilities/units/Unit.hpp"

#include "../utilities/core/Assert.hpp"

namespace openstudio {
namespace model {

namespace detail {

  SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl(const IdfObject& idfObject,
                                                                                                                       Model_Impl* model,
                                                                                                                       bool keepHandle)
    : ModelObject_Impl(idfObject,model,keepHandle)
  {
    OS_ASSERT(idfObject.iddObject().type() == SurfacePropertyConvectionCoefficientsMultipleSurface::iddObjectType());
  }

  SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                                                                                                       Model_Impl* model,
                                                                                                                       bool keepHandle)
    : ModelObject_Impl(other,model,keepHandle)
  {
    OS_ASSERT(other.iddObject().type() == SurfacePropertyConvectionCoefficientsMultipleSurface::iddObjectType());
  }

  SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl(const SurfacePropertyConvectionCoefficientsMultipleSurface_Impl& other,
                                                                                                                       Model_Impl* model,
                                                                                                                       bool keepHandle)
    : ModelObject_Impl(other,model,keepHandle)
  {}

  const std::vector<std::string>& SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::outputVariableNames() const
  {
    static std::vector<std::string> result;
    if (result.empty()){
    }
    return result;
  }

  IddObjectType SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::iddObjectType() const {
    return SurfacePropertyConvectionCoefficientsMultipleSurface::iddObjectType();
  }

  std::vector<ScheduleTypeKey> SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::getScheduleTypeKeys(const Schedule& schedule) const
  {
    // TODO: Check schedule display names.
    std::vector<ScheduleTypeKey> result;
    UnsignedVector fieldIndices = getSourceIndices(schedule.handle());
    UnsignedVector::const_iterator b(fieldIndices.begin()), e(fieldIndices.end());
    if (std::find(b,e,OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient1ScheduleName) != e)
    {
      result.push_back(ScheduleTypeKey("SurfacePropertyConvectionCoefficientsMultipleSurface","Convection Coefficient 1"));
    }
    if (std::find(b,e,OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient2ScheduleName) != e)
    {
      result.push_back(ScheduleTypeKey("SurfacePropertyConvectionCoefficientsMultipleSurface","Convection Coefficient 2"));
    }
    return result;
  }

  std::string SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::surfaceType() const {
    boost::optional<std::string> value = getString(OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::SurfaceType,true);
    OS_ASSERT(value);
    return value.get();
  }

  std::string SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::convectionCoefficient1Location() const {
    boost::optional<std::string> value = getString(OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient1Location,true);
    OS_ASSERT(value);
    return value.get();
  }

  std::string SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::convectionCoefficient1Type() const {
    boost::optional<std::string> value = getString(OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient1Type,true);
    OS_ASSERT(value);
    return value.get();
  }

  boost::optional<double> SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::convectionCoefficient1() const {
    return getDouble(OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient1,true);
  }

  boost::optional<Schedule> SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::convectionCoefficient1Schedule() const {
    return getObject<ModelObject>().getModelObjectTarget<Schedule>(OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient1ScheduleName);
  }

  boost::optional<UserConvectionModels> SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::convectionCoefficient1UserCurve() const {
    return getObject<ModelObject>().getModelObjectTarget<UserConvectionModels>(OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient1UserCurveName);
  }

  boost::optional<std::string> SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::convectionCoefficient2Location() const {
    return getString(OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient2Location,true);
  }

  boost::optional<std::string> SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::convectionCoefficient2Type() const {
    return getString(OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient2Type,true);
  }

  double SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::convectionCoefficient2() const {
    boost::optional<double> value = getDouble(OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient2,true);
    OS_ASSERT(value);
    return value.get();
  }

  bool SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::isConvectionCoefficient2Defaulted() const {
    return isEmpty(OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient2);
  }

  boost::optional<Schedule> SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::convectionCoefficient2Schedule() const {
    return getObject<ModelObject>().getModelObjectTarget<Schedule>(OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient2ScheduleName);
  }

  boost::optional<UserConvectionModels> SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::convectionCoefficient2UserCurve() const {
    return getObject<ModelObject>().getModelObjectTarget<UserConvectionModels>(OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient2UserCurveName);
  }

  bool SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::setSurfaceType(std::string surfaceType) {
    bool result = setString(OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::SurfaceType, surfaceType);
    return result;
  }

  bool SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::setConvectionCoefficient1Location(std::string convectionCoefficient1Location) {
    bool result = setString(OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient1Location, convectionCoefficient1Location);
    return result;
  }

  bool SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::setConvectionCoefficient1Type(std::string convectionCoefficient1Type) {
    bool result = setString(OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient1Type, convectionCoefficient1Type);
    return result;
  }

  void SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::setConvectionCoefficient1(boost::optional<double> convectionCoefficient1) {
    bool result(false);
    if (convectionCoefficient1) {
      result = setDouble(OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient1, convectionCoefficient1.get());
    }
    else {
      resetConvectionCoefficient1();
      result = true;
    }
    OS_ASSERT(result);
  }

  void SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::resetConvectionCoefficient1() {
    bool result = setString(OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient1, "");
    OS_ASSERT(result);
  }

  bool SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::setConvectionCoefficient1Schedule(Schedule& schedule) {
    bool result = setSchedule(OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient1ScheduleName,
                              "SurfacePropertyConvectionCoefficientsMultipleSurface",
                              "Convection Coefficient 1",
                              schedule);
    return result;
  }

  void SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::resetConvectionCoefficient1Schedule() {
    bool result = setString(OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient1ScheduleName, "");
    OS_ASSERT(result);
  }

  bool SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::setConvectionCoefficient1UserCurve(const boost::optional<UserConvectionModels>& userConvectionModels) {
    bool result(false);
    if (userConvectionModels) {
      result = setPointer(OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient1UserCurveName, userConvectionModels.get().handle());
    }
    else {
      resetConvectionCoefficient1UserCurve();
      result = true;
    }
    return result;
  }

  void SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::resetConvectionCoefficient1UserCurve() {
    bool result = setString(OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient1UserCurveName, "");
    OS_ASSERT(result);
  }

  bool SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::setConvectionCoefficient2Location(boost::optional<std::string> convectionCoefficient2Location) {
    bool result(false);
    if (convectionCoefficient2Location) {
      result = setString(OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient2Location, convectionCoefficient2Location.get());
    }
    else {
      resetConvectionCoefficient2Location();
      result = true;
    }
    return result;
  }

  void SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::resetConvectionCoefficient2Location() {
    bool result = setString(OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient2Location, "");
    OS_ASSERT(result);
  }

  bool SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::setConvectionCoefficient2Type(boost::optional<std::string> convectionCoefficient2Type) {
    bool result(false);
    if (convectionCoefficient2Type) {
      result = setString(OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient2Type, convectionCoefficient2Type.get());
    }
    else {
      resetConvectionCoefficient2Type();
      result = true;
    }
    return result;
  }

  void SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::resetConvectionCoefficient2Type() {
    bool result = setString(OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient2Type, "");
    OS_ASSERT(result);
  }

  void SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::setConvectionCoefficient2(double convectionCoefficient2) {
    bool result = setDouble(OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient2, convectionCoefficient2);
    OS_ASSERT(result);
  }

  void SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::resetConvectionCoefficient2() {
    bool result = setString(OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient2, "");
    OS_ASSERT(result);
  }

  bool SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::setConvectionCoefficient2Schedule(Schedule& schedule) {
    bool result = setSchedule(OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient2ScheduleName,
                              "SurfacePropertyConvectionCoefficientsMultipleSurface",
                              "Convection Coefficient 2",
                              schedule);
    return result;
  }

  void SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::resetConvectionCoefficient2Schedule() {
    bool result = setString(OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient2ScheduleName, "");
    OS_ASSERT(result);
  }

  bool SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::setConvectionCoefficient2UserCurve(const boost::optional<UserConvectionModels>& userConvectionModels) {
    bool result(false);
    if (userConvectionModels) {
      result = setPointer(OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient2UserCurveName, userConvectionModels.get().handle());
    }
    else {
      resetConvectionCoefficient2UserCurve();
      result = true;
    }
    return result;
  }

  void SurfacePropertyConvectionCoefficientsMultipleSurface_Impl::resetConvectionCoefficient2UserCurve() {
    bool result = setString(OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient2UserCurveName, "");
    OS_ASSERT(result);
  }

} // detail

SurfacePropertyConvectionCoefficientsMultipleSurface::SurfacePropertyConvectionCoefficientsMultipleSurface(const Model& model)
  : ModelObject(SurfacePropertyConvectionCoefficientsMultipleSurface::iddObjectType(),model)
{
  OS_ASSERT(getImpl<detail::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl>());

  // TODO: Appropriately handle the following required object-list fields.
  bool ok = true;
  // ok = setHandle();
  OS_ASSERT(ok);
  // ok = setSurfaceType();
  OS_ASSERT(ok);
  // ok = setConvectionCoefficient1Location();
  OS_ASSERT(ok);
  // ok = setConvectionCoefficient1Type();
  OS_ASSERT(ok);
}

IddObjectType SurfacePropertyConvectionCoefficientsMultipleSurface::iddObjectType() {
  return IddObjectType(IddObjectType::OS_SurfaceProperty_ConvectionCoefficients_MultipleSurface);
}

std::vector<std::string> SurfacePropertyConvectionCoefficientsMultipleSurface::surfaceTypeValues() {
  return getIddKeyNames(IddFactory::instance().getObject(iddObjectType()).get(),
                        OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::SurfaceType);
}

std::vector<std::string> SurfacePropertyConvectionCoefficientsMultipleSurface::convectionCoefficient1LocationValues() {
  return getIddKeyNames(IddFactory::instance().getObject(iddObjectType()).get(),
                        OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient1Location);
}

std::vector<std::string> SurfacePropertyConvectionCoefficientsMultipleSurface::convectionCoefficient1TypeValues() {
  return getIddKeyNames(IddFactory::instance().getObject(iddObjectType()).get(),
                        OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient1Type);
}

std::vector<std::string> SurfacePropertyConvectionCoefficientsMultipleSurface::convectionCoefficient2LocationValues() {
  return getIddKeyNames(IddFactory::instance().getObject(iddObjectType()).get(),
                        OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient2Location);
}

std::vector<std::string> SurfacePropertyConvectionCoefficientsMultipleSurface::convectionCoefficient2TypeValues() {
  return getIddKeyNames(IddFactory::instance().getObject(iddObjectType()).get(),
                        OS_SurfaceProperty_ConvectionCoefficients_MultipleSurfaceFields::ConvectionCoefficient2Type);
}

std::string SurfacePropertyConvectionCoefficientsMultipleSurface::surfaceType() const {
  return getImpl<detail::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl>()->surfaceType();
}

std::string SurfacePropertyConvectionCoefficientsMultipleSurface::convectionCoefficient1Location() const {
  return getImpl<detail::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl>()->convectionCoefficient1Location();
}

std::string SurfacePropertyConvectionCoefficientsMultipleSurface::convectionCoefficient1Type() const {
  return getImpl<detail::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl>()->convectionCoefficient1Type();
}

boost::optional<double> SurfacePropertyConvectionCoefficientsMultipleSurface::convectionCoefficient1() const {
  return getImpl<detail::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl>()->convectionCoefficient1();
}

boost::optional<Schedule> SurfacePropertyConvectionCoefficientsMultipleSurface::convectionCoefficient1Schedule() const {
  return getImpl<detail::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl>()->convectionCoefficient1Schedule();
}

boost::optional<UserConvectionModels> SurfacePropertyConvectionCoefficientsMultipleSurface::convectionCoefficient1UserCurve() const {
  return getImpl<detail::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl>()->convectionCoefficient1UserCurve();
}

boost::optional<std::string> SurfacePropertyConvectionCoefficientsMultipleSurface::convectionCoefficient2Location() const {
  return getImpl<detail::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl>()->convectionCoefficient2Location();
}

boost::optional<std::string> SurfacePropertyConvectionCoefficientsMultipleSurface::convectionCoefficient2Type() const {
  return getImpl<detail::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl>()->convectionCoefficient2Type();
}

double SurfacePropertyConvectionCoefficientsMultipleSurface::convectionCoefficient2() const {
  return getImpl<detail::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl>()->convectionCoefficient2();
}

bool SurfacePropertyConvectionCoefficientsMultipleSurface::isConvectionCoefficient2Defaulted() const {
  return getImpl<detail::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl>()->isConvectionCoefficient2Defaulted();
}

boost::optional<Schedule> SurfacePropertyConvectionCoefficientsMultipleSurface::convectionCoefficient2Schedule() const {
  return getImpl<detail::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl>()->convectionCoefficient2Schedule();
}

boost::optional<UserConvectionModels> SurfacePropertyConvectionCoefficientsMultipleSurface::convectionCoefficient2UserCurve() const {
  return getImpl<detail::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl>()->convectionCoefficient2UserCurve();
}

bool SurfacePropertyConvectionCoefficientsMultipleSurface::setSurfaceType(std::string surfaceType) {
  return getImpl<detail::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl>()->setSurfaceType(surfaceType);
}

bool SurfacePropertyConvectionCoefficientsMultipleSurface::setConvectionCoefficient1Location(std::string convectionCoefficient1Location) {
  return getImpl<detail::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl>()->setConvectionCoefficient1Location(convectionCoefficient1Location);
}

bool SurfacePropertyConvectionCoefficientsMultipleSurface::setConvectionCoefficient1Type(std::string convectionCoefficient1Type) {
  return getImpl<detail::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl>()->setConvectionCoefficient1Type(convectionCoefficient1Type);
}

void SurfacePropertyConvectionCoefficientsMultipleSurface::setConvectionCoefficient1(double convectionCoefficient1) {
  getImpl<detail::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl>()->setConvectionCoefficient1(convectionCoefficient1);
}

void SurfacePropertyConvectionCoefficientsMultipleSurface::resetConvectionCoefficient1() {
  getImpl<detail::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl>()->resetConvectionCoefficient1();
}

bool SurfacePropertyConvectionCoefficientsMultipleSurface::setConvectionCoefficient1Schedule(Schedule& schedule) {
  return getImpl<detail::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl>()->setConvectionCoefficient1Schedule(schedule);
}

void SurfacePropertyConvectionCoefficientsMultipleSurface::resetConvectionCoefficient1Schedule() {
  getImpl<detail::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl>()->resetConvectionCoefficient1Schedule();
}

bool SurfacePropertyConvectionCoefficientsMultipleSurface::setConvectionCoefficient1UserCurve(const UserConvectionModels& userConvectionModels) {
  return getImpl<detail::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl>()->setConvectionCoefficient1UserCurve(userConvectionModels);
}

void SurfacePropertyConvectionCoefficientsMultipleSurface::resetConvectionCoefficient1UserCurve() {
  getImpl<detail::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl>()->resetConvectionCoefficient1UserCurve();
}

bool SurfacePropertyConvectionCoefficientsMultipleSurface::setConvectionCoefficient2Location(std::string convectionCoefficient2Location) {
  return getImpl<detail::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl>()->setConvectionCoefficient2Location(convectionCoefficient2Location);
}

void SurfacePropertyConvectionCoefficientsMultipleSurface::resetConvectionCoefficient2Location() {
  getImpl<detail::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl>()->resetConvectionCoefficient2Location();
}

bool SurfacePropertyConvectionCoefficientsMultipleSurface::setConvectionCoefficient2Type(std::string convectionCoefficient2Type) {
  return getImpl<detail::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl>()->setConvectionCoefficient2Type(convectionCoefficient2Type);
}

void SurfacePropertyConvectionCoefficientsMultipleSurface::resetConvectionCoefficient2Type() {
  getImpl<detail::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl>()->resetConvectionCoefficient2Type();
}

void SurfacePropertyConvectionCoefficientsMultipleSurface::setConvectionCoefficient2(double convectionCoefficient2) {
  getImpl<detail::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl>()->setConvectionCoefficient2(convectionCoefficient2);
}

void SurfacePropertyConvectionCoefficientsMultipleSurface::resetConvectionCoefficient2() {
  getImpl<detail::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl>()->resetConvectionCoefficient2();
}

bool SurfacePropertyConvectionCoefficientsMultipleSurface::setConvectionCoefficient2Schedule(Schedule& schedule) {
  return getImpl<detail::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl>()->setConvectionCoefficient2Schedule(schedule);
}

void SurfacePropertyConvectionCoefficientsMultipleSurface::resetConvectionCoefficient2Schedule() {
  getImpl<detail::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl>()->resetConvectionCoefficient2Schedule();
}

bool SurfacePropertyConvectionCoefficientsMultipleSurface::setConvectionCoefficient2UserCurve(const UserConvectionModels& userConvectionModels) {
  return getImpl<detail::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl>()->setConvectionCoefficient2UserCurve(userConvectionModels);
}

void SurfacePropertyConvectionCoefficientsMultipleSurface::resetConvectionCoefficient2UserCurve() {
  getImpl<detail::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl>()->resetConvectionCoefficient2UserCurve();
}

/// @cond
SurfacePropertyConvectionCoefficientsMultipleSurface::SurfacePropertyConvectionCoefficientsMultipleSurface(std::shared_ptr<detail::SurfacePropertyConvectionCoefficientsMultipleSurface_Impl> impl)
  : ModelObject(impl)
{}
/// @endcond

} // model
} // openstudio

