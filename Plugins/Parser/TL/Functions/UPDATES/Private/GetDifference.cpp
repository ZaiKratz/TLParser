#include "../Public/GetDifference.h"


//begin namespace block
namespace UPDATES
{

GetDifference::GetDifference()
{
	this->_ConstructorID = 1368822565;
	this->_ContentRelated = true;
}

GetDifference::GetDifference(int32 pts, int32 pts_total_limit, FDateTime date, int32 qts)
{
	this->_ConstructorID = 1368822565;
	this->_ContentRelated = true;
	this->pts = pts;
	this->pts_total_limit = pts_total_limit;
	this->date = date;
	this->qts = qts;
}
void GetDifference::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!pts_total_limit)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteInt(this->pts);
	if(!this->pts_total_limit)
	{
	Writer.WriteInt(this->pts_total_limit);
	}
	Writer.TGWriteDate(this->date);
	Writer.WriteInt(this->qts);
}


void GetDifference::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<UPDATES::Difference*>(Reader.TGReadObject());
}
GetDifference::~GetDifference()
{

}
}//end namespace block
