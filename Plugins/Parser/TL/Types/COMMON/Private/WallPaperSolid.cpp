#include "../Public/WallPaperSolid.h"


//begin namespace block
namespace COMMON
{

WallPaperSolid::WallPaperSolid()
{
	this->_ConstructorID = 612307299;
}

WallPaperSolid::WallPaperSolid(int32 id, FString title, int32 bg_color, int32 color)
{
	this->_ConstructorID = 612307299;
	this->id = id;
	this->title = title;
	this->bg_color = bg_color;
	this->color = color;
}
void WallPaperSolid::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->id);
	Writer.TGWriteString(this->title);
	Writer.WriteInt(this->bg_color);
	Writer.WriteInt(this->color);
}


void WallPaperSolid::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadInt();
	title = Reader.TGReadString();
	bg_color = Reader.ReadInt();
	color = Reader.ReadInt();
}
WallPaperSolid::~WallPaperSolid()
{

}
}//end namespace block
