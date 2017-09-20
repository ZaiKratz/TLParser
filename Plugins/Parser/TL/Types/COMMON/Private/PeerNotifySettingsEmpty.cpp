#include "../Public/PeerNotifySettingsEmpty.h"


//begin namespace block
namespace COMMON
{

PeerNotifySettingsEmpty::PeerNotifySettingsEmpty()
{
	this->_ConstructorID = 310748784;
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
}
PeerNotifySettingsEmpty::~PeerNotifySettingsEmpty()
{

}
}//end namespace block
