#include "../Public/InputPrivacyValueAllowAll.h"


//begin namespace block
namespace COMMON
{

InputPrivacyValueAllowAll::InputPrivacyValueAllowAll()
{
	this->_ConstructorID = -835368168;
}
void InputPrivacyValueAllowAll::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputPrivacyValueAllowAll::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
InputPrivacyValueAllowAll::~InputPrivacyValueAllowAll()
{

}
}//end namespace block
