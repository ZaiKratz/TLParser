#include "../Public/InputPrivacyValueDisallowAll.h"


//begin namespace block
namespace COMMON
{

InputPrivacyValueDisallowAll::InputPrivacyValueDisallowAll()
{
	this->_ConstructorID = -916034602;
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
}
InputPrivacyValueDisallowAll::~InputPrivacyValueDisallowAll()
{

}
}//end namespace block
