#include <iostream>

/* initial version
namespace library {
  class Something {
      Something::Something() {
        std::cout << "library::v1::Something" << '\n';
      }
  };
}
*/

// version 2
namespace library {
  namespace v1 {
    class Something {
     public:
      Something() {
        std::cout << "library::v1::Something" << '\n';
      }
    };
  }

  inline namespace v2 {
    class Something {
     public:
      Something() {
        std::cout << "library::v2::Something" << '\n';
      }
    };
  }
}
