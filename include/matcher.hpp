# ifndef __MATCHER__H__
# define __MATCHER__H__

namespace uslam {
	
class Matcher {
public:	
	explicit Matcher() {}
	virtual ~Matcher() {}
	
	virtual void match() = 0;
}; // Matcher
	
} // namespace uslam

# endif