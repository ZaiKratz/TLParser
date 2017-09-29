#include "../Public/PeerNotifySettingsEmpty.h"


//begin namespace block
namespace COMMON
{

PeerNotifySettingsEmpty::PeerNotifySettingsEmpty()
{
	this->_ConstructorID = 1889961234;
}
void PeerNotifySettingsEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void PeerNotifySettingsEmpty::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
PeerNotifySettingsEmpty::~PeerNotifySettingsEmpty()
{

}
}//end namespace block
