#include "../Public/InputPrivacyValueDisallowAll.h"


//begin namespace block
namespace COMMON
{

InputPrivacyValueDisallowAll::InputPrivacyValueDisallowAll()
{
	this->_ConstructorID = -697604407;
}
void InputPrivacyValueDisallowAll::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputPrivacyValueDisallowAll::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
InputPrivacyValueDisallowAll::~InputPrivacyValueDisallowAll()
{

}
}//end namespace block
