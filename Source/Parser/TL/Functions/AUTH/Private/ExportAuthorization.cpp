#include "../Public/ExportAuthorization.h"


//begin namespace block
namespace AUTH
{

ExportAuthorization::ExportAuthorization()
{
	this->_ConstructorID = -440401971;
	this->_ContentRelated = true;
}

ExportAuthorization::ExportAuthorization(int32 dc_id)
{
	this->_ConstructorID = -440401971;
	this->_ContentRelated = true;
	this->dc_id = dc_id;
}
void ExportAuthorization::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->dc_id);
}


void ExportAuthorization::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<AUTH::ExportedAuthorization*>(Reader.TGReadObject());
	this->_Responded = true;
}
ExportAuthorization::~ExportAuthorization()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
