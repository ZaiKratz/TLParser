#include "../Public/InputPrivacyValueAllowAll.h"


//begin namespace block
namespace COMMON
{

InputPrivacyValueAllowAll::InputPrivacyValueAllowAll()
{
	this->_ConstructorID = 407582158;
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
	this->_Responded = true;
}
InputPrivacyValueAllowAll::~InputPrivacyValueAllowAll()
{
}
}//end namespace block
