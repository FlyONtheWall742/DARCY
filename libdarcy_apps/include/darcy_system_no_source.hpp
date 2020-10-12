// Example case with no sources and constant pressure on left and right boundaries

#include "darcy_system.hpp"
#include <cmath>
//#include "Eigen/Dense"

namespace Darcy_No_Source {
/**
   * @brief Example class for Darcy system implementation.
   * @details Sample implementation of a Darcy system. Uses a 0 RHS and constant boundary pressure.
   * @tparam T Base type for solution precision
   */
  template<typename T>
  class System : public Darcy::System<T> {
    using Darcy::System<T>::boundary;
  public:
    /**
     * @brief System Constructor
     * @param bound Vector containing the boundary locations (rectangular domain)
     */
    System(typename Darcy::System<T>::VTB bound);

    /**
     * @brief f Right-hand side of the system. Is 0 at all points.
     * @param x Point at which f is to be evaluated.
     * @return Value of RHS at given point. Always equal to 0 here.
     */
    T f(typename Darcy::System<T>::VTX x);

    /**
     * @brief pD Dirichlet boundary condition of the system. Is constant along left and right boundary.
     * @param x Point at which boundary condition is to be evaluated.
     * @return Pressure at given point. -1 if x is not on the boundary.
     */
    T pD(typename Darcy::System<T>::VTX x);
  };
}

#include "../src/darcy_system_no_source.cpp"
