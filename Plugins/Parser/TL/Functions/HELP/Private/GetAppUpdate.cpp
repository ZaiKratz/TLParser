#include "../Public/GetAppUpdate.h"


//begin namespace block
namespace HELP
{

GetAppUpdate::GetAppUpdate()
{
	this->_ConstructorID = -1763627602;
	this->_ContentRelated = true;
}
void GetAppUpdate::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void GetAppUpdate::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<HELP::AppUpdate*>(Reader.TGReadObject());
}
GetAppUpdate::~GetAppUpdate()
{

}
}//end namespace block
