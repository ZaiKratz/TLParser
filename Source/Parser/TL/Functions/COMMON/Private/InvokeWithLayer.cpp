#include "../Public/InvokeWithLayer.h"


//begin namespace block
namespace COMMON
{

InvokeWithLayer::InvokeWithLayer()
{
	this->_ConstructorID = -627372787;
	this->_ContentRelated = true;
}

InvokeWithLayer::InvokeWithLayer(int32 layer, TLBaseObject*  query)
{
	this->_ConstructorID = -627372787;
	this->_ContentRelated = true;
	this->layer = layer;
	this->query = query;
}
void InvokeWithLayer::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->layer);
	this->query->OnSend(Writer);
}


void InvokeWithLayer::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<TLBaseObject*>(Reader.TGReadObject());
	this->_Responded = true;
}
InvokeWithLayer::~InvokeWithLayer()
{

}
}//end namespace block
