
#include "scripting/ScriptingTestFixture.h"

class EnumsTest : public test::scripting::ScriptingTestFixture {
 public:
	EnumsTest() : test::scripting::ScriptingTestFixture(0) {
		pushModDir("enums");
	}
};

TEST_F(EnumsTest, enumExistance) {
	this->EvalTestScript();
}

TEST_F(EnumsTest, __tostring) {
	this->EvalTestScript();
}

TEST_F(EnumsTest, __eq) {
	this->EvalTestScript();
}
