function namefigs
% NAMEFIGS Name unnamed figures using concatenation of Y axis labels

for hfig = get(0,'Children')'
    fig = get(hfig);
    
    % if this figure is already named, skip it
    if fig.Name
        continue;
    end
    
    labels = [];
    children = fig.Children;
    
    use_mod = 1;
    if use_mod
        % added - 6/10/10
        % loop over children, which appear in reverse order of definition
        for ilabel = size(children,1):-1:1;
            dummy = get(children(ilabel));
            if isfield(dummy,'YLabel')
                label = get(dummy.YLabel);
                labelstr = label.String;
            else
                label = [];
                labelstr = [];
            end
           
            % tack on next label, if it is non-empty
            if(labelstr)
                % tack on separator after any existing labels
                if ~isempty(label)
                    if(labels)
                        labels = [labels ' // '];
                    end
                end
                labels = [labels labelstr];
            end
        end
    else
        % loop over children, which appear in reverse order of definition
        for ilabel = size(children,1):-1:1;
            label = get(get(children(ilabel),'YLabel'));
            labelstr = label.String;
            
            % tack on next label, if it is non-empty
            if(labelstr)
                % tack on separator after any existing labels
                if(labels)
                    labels = [labels ' // '];
                end
                
                labels = [labels labelstr];
            end
        end
    end
    
    if(labels)
        set(hfig, 'Name', labels);
    end
end