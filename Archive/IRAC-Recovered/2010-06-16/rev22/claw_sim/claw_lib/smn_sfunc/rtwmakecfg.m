function makeInfo=rtwmakecfg()
%RTWMAKECFG Add include and source directories to RTW make files.
%  makeInfo=RTWMAKECFG returns a structured array containing
%  following fields:
%
%     makeInfo.includePath - A cell array containing additional include
%                            directories. Those directories will be 
%                            expanded into include instructions of rtw 
%                            generated make files.
%     
%     makeInfo.sourcePath  - A cell array containing additional source
%                            directories. Those directories will be
%                            expanded into rules of rtw generated make
%                            files.
%
%     makeInfo.sources     - A cell array that specifies additional source
%                            filenames (C or C++), organized as a row
%                            vector. Real-Time Workshop expands the
%                            filenames into make variables that contain
%                            the source files. You should specify only
%                            filenames (with extension). Specify path
%                            information with the sourcePath field.

sfunc_name = get_value('smn_sfunc_name','MACH');
smn_root = get_value('smn_root');
sfunc_dir = fullfile(smn_root, sfunc_name);

makeInfo.includePath = { fullfile(sfunc_dir, 'c_code_smn') };

makeInfo.sourcePath = { sfunc_dir fullfile(sfunc_dir, 'c_code_smn') };

makeInfo.sources = {
    [ sfunc_name '_wrapper.c' ]
    'ch_smn_wrapper.c'
    'axpy_0ir20_1r20_1r.c'
    'axpy_0ir3_1r3_1r.c'
    'better_lam_bi_0rrrrrr.c'
    'better_lam_lo_0rrr.c'
    'compute_dgamma_0r3_3r3_1r3_1r3_1rii.c'
    'compute_eta_0i20_1r20_1r20_1r.c'
    'compute_gamma_0i20_1r20_1r.c'
    'compute_u_0r3_3r20_3r3_1r3_1riir.c'
    'controlh_types.c'
    'dot_0i20_1r20_1r.c'
    'dot_0i3_1r3_1r.c'
    'get_lam_bisect_0rrrr3_3r20_3r3_1r3_1r20_1r20_1rii.c'
    'get_unlwp_03_20r3_1r20_1r20_20riir.c'
    'get_wpplusnp_03_20r3_1r20_1r20_20r3_1rii.c'
    'ins_real_matrix_self.c'
    'interp_u_gamma_020_1r20_1r20_1ri.c'
    'mach_process_0_params_gv_0.c'
    'posdeffac_020_20rir.c'
    'posdeffac_03_3rir.c'
    'posdefsol_020_20r20_1riir.c'
    'posdefsol_020_20r20_3riir.c'
    'posdefsol_03_3r3_1riir.c'
    'round_real_matrix.c'
    'semn_03_20r3_1r3_1r20_1r20_20r20_1r20_1rrii.c'
    'smn_03_20r3_1r20_1r20_1r3_1r20_1r20_20r.c'
    'spmn_03_20r3_1r20_1r20_1r3_1r20_1r20_20rrii.c'
    };