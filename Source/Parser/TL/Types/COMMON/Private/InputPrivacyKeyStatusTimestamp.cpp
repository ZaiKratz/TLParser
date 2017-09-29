#include "../Public/InputPrivacyKeyStatusTimestamp.h"


//begin namespace block
namespace COMMON
{

InputPrivacyKeyStatusTimestamp::InputPrivacyKeyStatusTimestamp()
{
	this->_ConstructorID = 1335282456;
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
	this->_Responded = true;
}
InputPrivacyKeyStatusTimestamp::~InputPrivacyKeyStatusTimestamp()
{

}
}//end namespace block
