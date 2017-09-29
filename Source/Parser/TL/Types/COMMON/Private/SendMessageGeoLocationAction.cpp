#include "../Public/SendMessageGeoLocationAction.h"


//begin namespace block
namespace COMMON
{

SendMessageGeoLocationAction::SendMessageGeoLocationAction()
{
	this->_ConstructorID = 393186209;
}
void SendMessageGeoLocationAction::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void SendMessageGeoLocationAction::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
SendMessageGeoLocationAction::~SendMessageGeoLocationAction()
{

}
}//end namespace block
