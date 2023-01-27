#include "MyCollisions.hpp"

bool GetSphereNewPositionAndVelocityIfCollidingWithRoundedBox(Sphere sphere, RoundedBox rndBox, Vector3 velocity, float deltaTime, float& colT, Vector3& colSpherePos, Vector3& colNormal, Vector3& newPosition, Vector3& newVelocity) 
{
	// SI segment sphere entre en collision avec la Somme de Minkowski de la roundedBox ou Box (une roundedBox) alors calculer newPos + newVelocity 
	Segment seg_vel_sph = { sphere.ref.origin, Vector3Add(sphere.ref.origin, Vector3Scale(Vector3Normalize(velocity), sphere.radius)) }; // Point de collision de l'extérieur de la sphere
	RoundedBox minkowski = { rndBox.ref, { rndBox.extents.x + sphere.radius, rndBox.extents.y + sphere.radius, rndBox.extents.z + sphere.radius }, rndBox.radius };
	MyDrawRoundedBox(minkowski, 5, false, true);

	if (IntersectSegmentRoundedBox(seg_vel_sph, rndBox, colT, colSpherePos, colNormal)) {

		return true;
	}

	return false;
}


bool GetSphereNewPositionAndVelocityIfCollidingWithRoundedBoxes(Sphere sphere, const std::vector<RoundedBox>& rndBoxes, Vector3 velocity, float deltaTime, float& colT, Vector3& colSpherePos, Vector3& colNormal, Vector3& newPosition, Vector3& newVelocity) 
{
	return false;
}

bool GetSphereNewPositionAndVelocityIfMultiCollidingWithRoundedBoxes(Sphere sphere, const std::vector<RoundedBox>& rndBoxes, Vector3 velocity, float rotInertia, Vector3 angularMomentum, float deltaTime, int nMaxSuccessiveCollisions,
	Vector3& newPosition, Vector3& newVelocity, Vector3 newAngularMomentum)
{
	return false;
}
