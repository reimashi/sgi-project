#include "face3p.h"

namespace Engine {
	namespace Types {
		Face3P::Face3P(Point3D a, Point3D b, Point3D c, Vector3D v) : pointA(a), pointB(b), pointC(c), normal(v) {
		}

		Face3P::~Face3P() {}

		Point3D Face3P::getPointA() const { return this->pointA.clone(); }
		Point3D Face3P::getPointB() const { return this->pointB.clone(); }
		Point3D Face3P::getPointC() const { return this->pointC.clone(); }
		Vector3D Face3P::getNormal() const { return *this->normal.clone(); }

		Face3P* Face3P::clone() const {
			return new Face3P(this->getPointA(), this->getPointB(), this->getPointC(), this->getNormal());
		}

		bool Face3P::operator==(const Face3P& rhs) const
		{
			return (this->pointA == rhs.getPointA()
				&& this->pointB == rhs.getPointB()
				&& this->pointC == rhs.getPointC()
				&& this->normal == rhs.getNormal());
		}

		bool Face3P::operator!=(const Face3P& rhs) const
		{
			return !operator==(rhs);
		}
	}
}