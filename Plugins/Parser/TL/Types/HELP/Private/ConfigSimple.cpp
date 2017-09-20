#include "../Public/ConfigSimple.h"


//begin namespace block
namespace HELP
{

ConfigSimple::ConfigSimple()
{
	this->_ConstructorID = -977037351;
}

ConfigSimple::ConfigSimple(FDateTime date, FDateTime expires, int32 dc_id, TArray<COMMON::ipPort*> ip_port_list)
{
	this->_ConstructorID = -977037351;
	this->date = date;
	this->expires = expires;
	this->dc_id = dc_id;
	this->ip_port_list = ip_port_list;
}
void ConfigSimple::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteDate(this->date);
	Writer.TGWriteDate(this->expires);
	Writer.WriteInt(this->dc_id);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->ip_port_list.Num());
	for(auto X : this->ip_port_list)
	{
	X->OnSend(Writer);
	}
}


void ConfigSimple::OnResponce(BinaryReader& Reader)
{
	date = Reader.TGReadDate();
	expires = Reader.TGReadDate();
	dc_id = Reader.ReadInt();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len26211 = Reader.ReadInt();
	for(int32 i = 0; i < Len26211; i++)
	{
	auto X = reinterpret_cast<COMMON::ipPort*>(Reader.TGReadObject());
	ip_port_list.Add(X);
	}
}
ConfigSimple::~ConfigSimple()
{

}
}//end namespace block
