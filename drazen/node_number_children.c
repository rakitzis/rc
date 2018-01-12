#include <assert.h>
#define sizeof_array(x) ((int)(sizeof(x) / sizeof((x)[0])))

extern int printf(const char* fmt, ...);

typedef enum nodetype {
	nAndalso, nAssign, nBackq, nBang, nBody, nCbody, nNowait, nBrace,
	nConcat, nCount, nElse, nFlat, nDup, nEpilog, nNewfn, nForin, nIf,
	nOrelse, nPipe, nPre, nRedir, nRmfn, nArgs, nSubshell, nCase,
	nSwitch, nMatch, nVar, nVarsub, nWhile, nWord, nLappend, nNmpipe
} nodetype;


typedef struct ChildCountToNodes {
    int m_NumNodes;
    nodetype m_Nodes[19];
} ChildCountToNodes;


/**********************************************************************/
/* This is C99 initialization syntax. */
const int
node_to_child_count[33] = {
    [nBang]     = 1,
    [nNowait]   = 1,
    [nCase]     = 1,
    [nCount]    = 1,
    [nFlat]     = 1,
    [nRmfn]     = 1,
    [nSubshell] = 1,
    [nVar]      = 1,

    [nAndalso]  = 2,
    [nAssign]   = 2,
    [nBackq]    = 2,
    [nBody]     = 2,
    [nBrace]    = 2,
    [nConcat]   = 2,
    [nElse]     = 2,
    [nEpilog]   = 2,
    [nIf]       = 2,
    [nNewfn]    = 2,
    [nCbody]    = 2,
    [nOrelse]   = 2,
    [nPre]      = 2,
    [nArgs]     = 2,
    [nSwitch]   = 2,
    [nMatch]    = 2,
    [nVarsub]   = 2,
    [nWhile]    = 2,
    [nLappend]  = 2,

    [nForin]    = 3,
    [nRedir]    = 3,
    [nNmpipe]   = 3,
    [nDup]      = 3,
    [nWord]     = 3,

    [nPipe]     = 4,
};



/**********************************************************************/
const ChildCountToNodes
child_count_to_nodes[5] = {
    [0] = {
        .m_NumNodes = 0
    },
    [1] = {
        .m_NumNodes = 8,
        .m_Nodes = {
            nBang,
            nNowait,
            nCase,
            nCount,
            nFlat,
            nRmfn,
            nSubshell,
            nVar,
        },
    },

    [2] = {
        .m_NumNodes = 19,
        .m_Nodes = {
            nAndalso,
            nAssign,
            nBackq,
            nBody,
            nBrace,
            nConcat,
            nElse,
            nEpilog,
            nIf,
            nNewfn,
            nCbody,
            nOrelse,
            nPre,
            nArgs,
            nSwitch,
            nMatch,
            nVarsub,
            nWhile,
            nLappend,
        },
    },
    [3] = {
        .m_NumNodes = 5,
        .m_Nodes = {
            nForin,
            nRedir,
            nNmpipe,
            nDup,
            nWord,
        },
    },
    [4] = {
        .m_NumNodes = 1,
        .m_Nodes = {
            nPipe,
        },
    },
};


/**********************************************************************/
/**********************************************************************/
/**********************************************************************/
extern int printf(const char* fmt, ...);

int
main()
{

    {
        int total_nodes = 0;
        int cld_cnt;
        for (cld_cnt = 0; cld_cnt < sizeof_array(child_count_to_nodes); ++cld_cnt) {
            const ChildCountToNodes* const cldcnt2nodes = &child_count_to_nodes[cld_cnt];
            total_nodes += cldcnt2nodes->m_NumNodes;
            int nd_idx;

            for (nd_idx = 0; nd_idx < cldcnt2nodes->m_NumNodes; ++nd_idx) {
                const nodetype nd2 = cldcnt2nodes->m_Nodes[nd_idx];
                assert(node_to_child_count[nd2] == cld_cnt);
            }
        }
        assert(total_nodes == sizeof_array(node_to_child_count));
    }

    {
        nodetype nd1;
        for (nd1 = 0; nd1 < sizeof_array(node_to_child_count); ++nd1) {
            const int cld_cnt1 = node_to_child_count[nd1];
            int found = 0;
            int cld_cnt2;
            for (cld_cnt2 = 0; cld_cnt2 < sizeof_array(child_count_to_nodes); ++cld_cnt2) {
                const ChildCountToNodes* const cldcnt2nodes = &child_count_to_nodes[cld_cnt2];
                int nd_idx2;

                for (nd_idx2 = 0; nd_idx2 < cldcnt2nodes->m_NumNodes; ++nd_idx2) {
                    if (cldcnt2nodes->m_Nodes[nd_idx2] == nd1) { /* found nd in nodes for cld_cnt2 */
                        assert(cld_cnt2 == cld_cnt1);
                        found = 1;
                        break;
                    }
                }
                if (found) {
                    break;
                }
            }
            assert(found);
        }
    }
}

