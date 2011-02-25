#ifndef KOCMOC_UTIL_UTIL_HPP_
#define KOCMOC_UTIL_UTIL_HPP_


#include <glm.hpp>

#include <vector>


namespace kocmoc
{
	namespace scene
	{
		class LineGizmo;
	}

	namespace renderer
	{
		class RenderMesh;
	}

	namespace util
	{

		/**
		 * Check if the given file exists on the file system.
		 */
		bool file_exists(const std::string &filename);

		/**
		 * Read the given file into a String
		 */
		std::string read_file(const std::string &filename);

		/**
		 * Safe delete an array
		 * only delete if not null and set null afterwards
		 */
		void safeDeleteArray(void *p);

		void tokenize(const std::string& str, std::vector<std::string >& tokens, const std::string& delimiter);

		namespace generator
		{
			/**
			 * generate a starfield and take the needed params from the config
			 * file
			 */
			kocmoc::renderer::RenderMesh* generateStars();

			/**
			 * Generate a colored coordinate cross gizmo
			 */
			kocmoc::scene::LineGizmo* generateOriginGizmo();

			/**
			 * Generates a unit cube to arround the origin 
			 */
			kocmoc::scene::LineGizmo* generateUnitCube();

			kocmoc::renderer::RenderMesh* generateTriangle();
		}

		namespace geometry
		{
			/**
			 * test if a point is inside, i.e. not on the side of the 
			 * normal vector that is pointing towards the outside
			 * @return true iff the point is inside or directly on the plane
			 */
			bool inside(const double d, const glm::dvec3& n, const glm::dvec3& point);

			/**
			 * calculate the intersection parameter for a later
			 * linear mix. It is assumed that there is a valid 
			 * intersection point!
			 */
			double intersect(const double d, const glm::dvec3& n, const glm::dvec3& p1, const glm::dvec3& p2);

			/**
			 * linear combination 
			 */
			template <typename T >
			T lerp(const double r, const T& v1, const T& v2)
			{
				return (v1 * r) + (v2 * (1-r));
			}
		}
	}
}


#endif