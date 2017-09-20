#include "../Public/InputPrivacyKeyStatusTimestamp.h"


//begin namespace block
namespace COMMON
{

InputPrivacyKeyStatusTimestamp::InputPrivacyKeyStatusTimestamp()
{
	this->_ConstructorID = 415995471;
}
void InputPrivacyKeyStatusTimestamp::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputPrivacyKeyStatusTimestamp::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
InputPrivacyKeyStatusTimestamp::~InputPrivacyKeyStatusTimestamp()
{

}
}//end namespace block
