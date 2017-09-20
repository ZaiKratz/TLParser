#include "../Public/SendMessageGeoLocationAction.h"


//begin namespace block
namespace COMMON
{

SendMessageGeoLocationAction::SendMessageGeoLocationAction()
{
	this->_ConstructorID = -1584697577;
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
}
SendMessageGeoLocationAction::~SendMessageGeoLocationAction()
{

}
}//end namespace block
