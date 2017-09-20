#include "../Public/ExportAuthorization.h"


//begin namespace block
namespace AUTH
{

ExportAuthorization::ExportAuthorization()
{
	this->_ConstructorID = -838877211;
	this->_ContentRelated = true;
}

ExportAuthorization::ExportAuthorization(int32 dc_id)
{
	this->_ConstructorID = -838877211;
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
}
ExportAuthorization::~ExportAuthorization()
{

}
}//end namespace block
