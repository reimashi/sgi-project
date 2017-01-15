#include "vector3d.h"
#include <cmath>

namespace Engine {
	namespace Types {
		Vector3D::Vector3D(Point3D init, Point3D term) : initial(init), terminal(term)
		{
		}

		Vector3D::~Vector3D()
		{
		}

		Point3D Vector3D::getInitialPoint() const { return *(this->initial.clone()); }
		Point3D Vector3D::getTerminalPoint() const { return *(this->terminal.clone()); }
		float_t Vector3D::getMagnitude() const
		{
			return sqrtf(powf(this->initial.getX(), 2) + powf(this->initial.getY(), 2) + powf(this->initial.getZ(), 2));
		}

		Vector3D* Vector3D::clone() const
		{
			return new Vector3D(*this->initial.clone(), *this->terminal.clone());
		}

		bool Vector3D::operator==(const Vector3D& rhs) const {
			return (this->initial == rhs.getInitialPoint()
				&& this->terminal == rhs.getTerminalPoint());
		}

		bool Vector3D::operator!=(const Vector3D& rhs) const {
			return !operator==(rhs);
		}
	}
}