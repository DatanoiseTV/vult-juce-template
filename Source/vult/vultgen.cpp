
/* Code automatically generated by Vult https://github.com/modlfo/vult */
#include "vultgen.h"

void Selfplay__ctx_type_16_init(Selfplay__ctx_type_16 &_output_){
   Selfplay__ctx_type_16 _ctx;
   _ctx.rate = 0.0f;
   _ctx.phase = 0.0f;
   Selfplay__ctx_type_0_init(_ctx._inst11a);
   Selfplay_phase_start(_ctx);
   _output_ = _ctx;
   return ;
}

float Selfplay_phase(Selfplay__ctx_type_16 &_ctx, float cv){
   if(Selfplay_change(_ctx._inst11a,cv)){
      _ctx.rate = Selfplay_cvToRate(cv);
   }
   _ctx.phase = (_ctx.phase + _ctx.rate);
   if(_ctx.phase > 1.f){
      _ctx.phase = (-1.f + _ctx.phase);
   }
   return _ctx.phase;
}

void Selfplay__ctx_type_17_init(Selfplay__ctx_type_17 &_output_){
   Selfplay__ctx_type_17 _ctx;
   _ctx.rate = 0.0f;
   _ctx.phase = 0.0f;
   Selfplay__ctx_type_0_init(_ctx._inst11a);
   _output_ = _ctx;
   return ;
}

float Selfplay_lfo(Selfplay__ctx_type_17 &_ctx, float cv){
   if(Selfplay_change(_ctx._inst11a,cv)){
      _ctx.rate = (0.00025f * cv);
   }
   _ctx.phase = (_ctx.phase + _ctx.rate);
   if(_ctx.phase > 1.f){
      _ctx.phase = (-1.f + _ctx.phase);
   }
   return _ctx.phase;
}

void Selfplay__ctx_type_19_init(Selfplay__ctx_type_19 &_output_){
   Selfplay__ctx_type_19 _ctx;
   _ctx.out = 0.0f;
   Selfplay__ctx_type_2_init(_ctx._inst364);
   Selfplay__ctx_type_1_init(_ctx._inst132);
   _output_ = _ctx;
   return ;
}

void Selfplay__ctx_type_20_init(Selfplay__ctx_type_20 &_output_){
   Selfplay__ctx_type_20 _ctx;
   _ctx.out = 0.0f;
   Selfplay__ctx_type_2_init(_ctx._inst164);
   _output_ = _ctx;
   return ;
}

void Selfplay__ctx_type_21_init(Selfplay__ctx_type_21 &_output_){
   Selfplay__ctx_type_21 _ctx;
   Selfplay__ctx_type_19_init(_ctx._inst9cc);
   Selfplay__ctx_type_18_init(_ctx._inst8b2);
   Selfplay__ctx_type_19_init(_ctx._inst7cc);
   Selfplay__ctx_type_18_init(_ctx._inst6b2);
   Selfplay__ctx_type_18_init(_ctx._inst5b2);
   Selfplay__ctx_type_19_init(_ctx._inst4cc);
   Selfplay__ctx_type_17_init(_ctx._inst338);
   Selfplay__ctx_type_17_init(_ctx._inst238);
   Selfplay__ctx_type_20_init(_ctx._inst13e5);
   Selfplay__ctx_type_17_init(_ctx._inst138);
   Selfplay__ctx_type_18_init(_ctx._inst12b2);
   Selfplay__ctx_type_19_init(_ctx._inst11cc);
   Selfplay__ctx_type_18_init(_ctx._inst10b2);
   _output_ = _ctx;
   return ;
}

float Selfplay_process(Selfplay__ctx_type_21 &_ctx, float input){
   float lfo1;
   lfo1 = Selfplay_lfo(_ctx._inst138,0.01f);
   float lfo2;
   lfo2 = Selfplay_lfo(_ctx._inst238,0.2f);
   float lfo3;
   lfo3 = Selfplay_lfo(_ctx._inst338,0.1f);
   float mod1;
   mod1 = (0.1f * lfo1);
   float mod2;
   mod2 = Selfplay_osc(_ctx._inst5b2,Selfplay_shnoise(_ctx._inst4cc,lfo3));
   float o1;
   o1 = (Selfplay_osc(_ctx._inst6b2,(0.3f + mod1)) * Selfplay_shnoise(_ctx._inst7cc,lfo2));
   float o2;
   o2 = (Selfplay_osc(_ctx._inst8b2,(0.4f + (- mod1))) * Selfplay_shnoise(_ctx._inst9cc,lfo2));
   float o3;
   o3 = (Selfplay_osc(_ctx._inst10b2,(0.4f + (0.3f * mod2))) * Selfplay_shnoise(_ctx._inst11cc,lfo3));
   float o4;
   o4 = (1.5f * Selfplay_osc(_ctx._inst12b2,(0.1f + (0.1f * mod2))) * Selfplay_pulse(_ctx._inst13e5,lfo2));
   return (o1 + o2 + o3 + o4);
}

