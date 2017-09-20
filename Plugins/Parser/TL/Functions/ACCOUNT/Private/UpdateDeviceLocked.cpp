#include "../Public/UpdateDeviceLocked.h"


//begin namespace block
namespace ACCOUNT
{

UpdateDeviceLocked::UpdateDeviceLocked()
{
	this->_ConstructorID = 842391352;
	this->_ContentRelated = true;
}

UpdateDeviceLocked::UpdateDeviceLocked(int32 period)
{
	this->_ConstructorID = 842391352;
	this->_ContentRelated = true;
	this->period = period;
}
void UpdateDeviceLocked::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->period);
}


void UpdateDeviceLocked::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
}
UpdateDeviceLocked::~UpdateDeviceLocked()
{

}
}//end namespace block