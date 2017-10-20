#include "../Public/GetAppUpdate.h"


//begin namespace block
namespace HELP
{

GetAppUpdate::GetAppUpdate()
{
	this->_ConstructorID = -1372724842;
	this->_ContentRelated = true;
}
void GetAppUpdate::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void GetAppUpdate::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<HELP::AppUpdate*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetAppUpdate::~GetAppUpdate()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
